//State.cpp
#include "State.h"
#include <iostream>
#include <sstream>
#include <ctime>

#include <AtUtility/Renderer.h>
#include <AtUtility/Lua.h>

using namespace AtUtility;

static const int SDL_CUSTOM_CTRL       = 1001;
static const int SDL_CUSTOM_SHIFT      = 1002;
static const int SDL_CUSTOM_ALT        = 1003;
static const int SDL_CUSTOM_LMB        = 1004;
static const int SDL_CUSTOM_RMB        = 1005;
static const int SDL_CUSTOM_MMB        = 1006;
static const int SDL_CUSTOM_X1MB       = 1007;
static const int SDL_CUSTOM_X2MB       = 1008;
static const int SDL_CUSTOM_WHEELUP    = 1009;
static const int SDL_CUSTOM_WHEELDOWN  = 1010;

namespace AtApp {
    /// Enables or disables resizing of the application window.
    void State::AllowResize(bool State) {
        Resizable = State;
    }

    /// Applies current video mode settings.
    void State::ApplyVideoMode() {
        if (Window) {
            //Flag for VideoMode change
            bool Flag = false;
            Uint32 Flags = SDL_GetWindowFlags(Window);

            int Width = 0, Height = 0;
            SDL_GetWindowSize(Window, &Width, &Height);

            if (Width != GetWidth() || Height != GetHeight()) {
                Flag = true;
                //std::cout << "case 0" << std::endl;
                EventQueue.push_back(Events::ResolutionChanged);
            } else {
                if ((SDL_GL_GetSwapInterval() && !VSync) || (VSync && !SDL_GL_GetSwapInterval())) {
                    Flag = true;
                } else {
                    if (Flags&SDL_WINDOW_FULLSCREEN) {
                        if (WindowMode == WindowModes::Windowed) {
                            Flag = true;
                        } else {
                            if ((Flags&SDL_WINDOW_FULLSCREEN) == (Flags&SDL_WINDOW_FULLSCREEN_DESKTOP)) {
                                //std::cout << "case 1" << std::endl;
                                if (WindowMode == WindowModes::Borderless) Flag = true;
                            } else {
                                //std::cout << "case 2" << std::endl;
                                if (WindowMode == WindowModes::Fullscreen) Flag = true;
                            }
                        }
                    } else if (!(Flags&SDL_WINDOW_FULLSCREEN) && WindowMode != WindowModes::Windowed) {
                        //std::cout << "case 3" << std::endl;
                        Flag = true;
                    } else if (WindowMode == WindowModes::Maximised && !(Flags&SDL_WINDOW_MAXIMIZED)) {
                        Flag = true;
                        //std::cout << "case 4" << std::endl;
                    }
                }
            }

            //std::cout << Flag << " " << (Flags&SDL_WINDOW_FULLSCREEN) << " " << (Flags&SDL_WINDOW_FULLSCREEN_DESKTOP) << " " << (Flags&SDL_WINDOW_BORDERLESS) << " " << (Flags&SDL_WINDOW_MAXIMIZED) << std::endl;

            //Apply VideoMode
            if (Flag) {
                if (WindowMode == WindowModes::Windowed) {
                    SDL_RestoreWindow(Window);
                    SDL_SetWindowFullscreen(Window, 0);

                    SDL_SetWindowSize(Window, WindowedResolution.X(), WindowedResolution.Y());
                    SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex), SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex));
                    SDL_SetWindowDisplayMode(Window, NULL);
                    if (Bordered) SDL_SetWindowBordered(Window, SDL_TRUE); else SDL_SetWindowBordered(Window, SDL_FALSE);

                    Renderer::Setup2D(WindowedResolution.X(), WindowedResolution.Y());
                    Renderer::SetViewport(WindowedResolution.X(), WindowedResolution.Y());
                } else if (WindowMode == WindowModes::Fullscreen) {
                    SDL_RestoreWindow(Window);
                    SDL_SetWindowDisplayMode(Window, NULL);
                    SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN);

                    SDL_SetWindowSize(Window, FullscreenResolution.X(), FullscreenResolution.Y());
                    //SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex), SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex));

                    Renderer::Setup2D(FullscreenResolution.X(), FullscreenResolution.Y());
                } else if (WindowMode == WindowModes::Borderless) {
                    SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    SDL_SetWindowBordered(Window, SDL_FALSE);

                    SDL_DisplayMode Desktop;
                    SDL_GetDesktopDisplayMode(DisplayIndex, &Desktop);

                    SDL_SetWindowSize(Window, Desktop.w, Desktop.h);
                    //SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex), SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex));
                    SDL_SetWindowDisplayMode(Window, NULL);

                    Renderer::Setup2D(Desktop.w, Desktop.h);
                    Renderer::SetViewport(Desktop.w, Desktop.h);
                } else if (WindowMode == WindowModes::Maximised) {
                    SDL_MaximizeWindow(Window);

                    int Width = GetWidth(), Height = GetHeight();

                    Renderer::Setup2D(Width, Height);
                    Renderer::SetViewport(Width, Height);
                    EventQueue.push_back(Events::ResolutionChanged);
                }
            }

            if (VSync) SDL_GL_SetSwapInterval(1); else  SDL_GL_SetSwapInterval(0);
        }
    }

    /// Checks if input is allowed.
    /** Used to regulate the speed of user input when a large number of input events are generated by the user. */
    bool State::CanInput() {
        bool CanInput = false;

        if (NextInput <= GetRuntime()) {
            CanInput = true;
            NextInput = GetRuntime()+GetInputTimeStep();
            InputCount += 1;
        }

        return CanInput;
    }

    /// Checks if the application is allowed to complete a process loop.
    /** Used to regulate the speed of the main game loop. */
    bool State::CanProcess() {
        bool CanProcess = false;

        if (NextProcess <= GetRuntime() && RenderSkips <= MaximumRenderSkips) {
            CanProcess = true;
            NextProcess += GetProcessTimeStep();
            RenderSkips += 1;
            ProcessCount += 1;

            //Handle Events
            for (int i=0; i<(signed)EventQueue.size(); i++) {
                int Event = EventQueue[i];

                if (Event == Events::ResolutionChanged) {
                    Lua::ExecuteScript(Lua, "Application.OnGlobalEvent(\"ResolutionChanged\");");
                }
            }
            EventQueue.clear();
        }

        return CanProcess;
    }

    /// Closes the application window.
    void State::Close() {
        if (Status) Status = false;
        if (GLContext) SDL_GL_DeleteContext(GLContext);
        if (Window) SDL_DestroyWindow(Window);
        SDL_Quit();
    }

    /// Returns the number of permitted display modes.
    /** The returned number of display modes is referring to the current display, set by DisplayIndex. */
    int State::GetAvailableVideoModes() {
        return SDL_GetNumDisplayModes(DisplayIndex);
    }

    /// Returns the index of the display the application is assigned to.
    int State::GetDisplayIndex() {
        return DisplayIndex;
    }

    /// Returns the framerate of the application.
    /** The framerate is measured and updated once every second. */
    int State::GetFramerate() {
        return Framerate;
    }

    /// Returns the height of the application window.
    /** @param WindowMode If specified, the function will return the height for that window mode. If not specified, the height for the current window mode will be returned. */
    int State::GetHeight(int WindowMode) {
        int Height = 0;

        if (WindowMode < 0) WindowMode = this->WindowMode;

        if (WindowMode == WindowModes::Windowed) {
            Height = WindowedResolution.Y();
        } else if (WindowMode == WindowModes::Fullscreen) {
            Height = FullscreenResolution.Y();
        } else if (WindowMode == WindowModes::Borderless) {
            SDL_DisplayMode DisplayMode;
            SDL_GetDesktopDisplayMode(DisplayIndex, &DisplayMode);
            Height = DisplayMode.h;
        } else if (WindowMode == WindowModes::Maximised) {
            int W = 0;

            if (Window) SDL_GetWindowSize(Window, &W, &Height);
        }

        return Height;
    }

    /// Returns the minimum time interval at which input events are processed.
    float State::GetInputTimeStep() {
        return (IPS?1.f/IPS:0);
    }

    /// Returns a value which may be used to interpolate the position of objects during rendering.
    float State::GetInterpolation() {
        float Interpolation = (GetRuntime()+GetProcessTimeStep()-NextProcess)/GetProcessTimeStep();
        if (Interpolation > 1.f) Interpolation = 1.f;
        return Interpolation;
    }

    /// Returns the maximum allowed rate of input events.
    int State::GetIPS() {
        return IPS;
    }

    /// Returns the process speed of the main game loop.
    int State::GetPPS() {
        return PPS;
    }

    /// Used to check if a specified key is pressed.
    /** @param Key Uses the SDL_Scancode enumeration. Supports some custom definitions such as SDL_CUSTOM_SHIFT. */
    int State::IsKeyPressed(SDL_Scancode Key) {
        const Uint8 *Keyboard = SDL_GetKeyboardState(NULL);
        if (Key == SDL_CUSTOM_CTRL) {
            return (Keyboard[SDL_SCANCODE_LCTRL] || Keyboard[SDL_SCANCODE_RCTRL]);
        } else if (Key == SDL_CUSTOM_SHIFT) {
            return (Keyboard[SDL_SCANCODE_LSHIFT] || Keyboard[SDL_SCANCODE_RSHIFT]);
        } else if (Key == SDL_CUSTOM_ALT) {
            return (Keyboard[SDL_SCANCODE_LALT] || Keyboard[SDL_SCANCODE_RALT]);
        } else {
            if (Keyboard[Key]) return true; else return false;
        }
    }

    /// Returns the minimum time interval between two game process loops.
    float State::GetProcessTimeStep() {
        return (PPS?1.f/PPS:0);
    }

    /// Returns the current runtime of the application in seconds.
    float State::GetRuntime() {
        return SDL_GetTicks()/1000.f;
    }

    /// Returns the width of the application window.
    /** @param WindowMode If specified, the function will return the width for that window mode. If not specified, the width for the current window mode will be returned. */
    int State::GetWidth(int WindowMode) {
        int Width = 0;

        if (WindowMode < 0) WindowMode = this->WindowMode;

        if (WindowMode == WindowModes::Windowed) {
            Width = WindowedResolution.X();
        } else if (WindowMode == WindowModes::Fullscreen) {
            Width = FullscreenResolution.X();
        } else if (WindowMode == WindowModes::Borderless) {
            SDL_DisplayMode DisplayMode;
            SDL_GetDesktopDisplayMode(DisplayIndex, &DisplayMode);
            Width = DisplayMode.w;
        } else if (WindowMode == WindowModes::Maximised) {
            int H = 0;

            if (Window) SDL_GetWindowSize(Window, &Width, &H);
        }

        return Width;
    }

    /// Returns the VSync property.
    bool State::GetVSync() {
        return VSync;
    }

    /// Returns the WindowMode property.
    int State::GetWindowMode() {
        return WindowMode;
    }

    /// Returns the video mode at the specified index.
    /** The returned string is in the following format: "(Width)x(Height)". */
    std::string State::GetVideoMode(int i) {
        std::stringstream GetAvailableMode;

        SDL_DisplayMode DisplayMode;
        SDL_GetDisplayMode(DisplayIndex, i, &DisplayMode);

        GetAvailableMode << DisplayMode.w << "x" << DisplayMode.h;

        return GetAvailableMode.str();
    }

    /// Hides the application window.
    void State::Hide() {
        if (Window) {
            SDL_HideWindow(Window);
        }
    }

    /// Used to handle all SDL input events.
    int State::Input(SDL_Event &Event) {
        int Input = 0;

        if (!Input) {
            if (Event.type == SDL_KEYDOWN || Event.type == SDL_KEYUP) {
                if (Event.key.repeat == 0) {
                    if (Event.key.keysym.scancode != SDL_SCANCODE_APPLICATION
                        && Event.key.keysym.scancode != SDL_SCANCODE_LGUI
                        && Event.key.keysym.scancode != SDL_SCANCODE_RGUI
                        && Event.key.keysym.scancode != SDL_SCANCODE_LALT
                        && Event.key.keysym.scancode != SDL_SCANCODE_LSHIFT
                        && Event.key.keysym.scancode != SDL_SCANCODE_LCTRL
                        && Event.key.keysym.scancode != SDL_SCANCODE_RALT
                        && Event.key.keysym.scancode != SDL_SCANCODE_RSHIFT
                        && Event.key.keysym.scancode != SDL_SCANCODE_RCTRL
                    ) {
                        std::ostringstream Stream;
                        Stream << Event.key.keysym.scancode;

                        std::string EventString;
                        if (Event.type == SDL_KEYDOWN) EventString = "KeyDown"; else if (Event.type == SDL_KEYUP) EventString = "KeyUp";

                        Lua::ExecuteScript(Lua, "Application.OnGlobalEvent(\"" + EventString + "\", " + Stream.str() + ");");
                    }
                }
            } else if (Event.type == SDL_MOUSEBUTTONDOWN || Event.type == SDL_MOUSEBUTTONUP) {
                std::ostringstream Stream;
                bool Pass = true;

                switch (Event.button.button) {
                    case SDL_BUTTON_LEFT:
                    case SDL_BUTTON_RIGHT:
                        Pass = false;
                        break;
                    case SDL_BUTTON_MIDDLE:
                        Stream << SDL_CUSTOM_MMB;
                        break;
                    case SDL_BUTTON_X1:
                        Stream << SDL_CUSTOM_X1MB;
                        break;
                    case SDL_BUTTON_X2:
                        Stream << SDL_CUSTOM_X2MB;
                        break;
                    default:
                        break;
                }

                if (Pass) {
                    std::string EventString;
                    if (Event.type == SDL_MOUSEBUTTONDOWN) EventString = "KeyDown"; else if (Event.type == SDL_MOUSEBUTTONUP) EventString = "KeyUp";

                    Lua::ExecuteScript(Lua, "Application.OnGlobalEvent(\"" + EventString + "\", " + Stream.str() + ");");
                }
            } else if (Event.type == SDL_MOUSEWHEEL) {
                std::ostringstream Stream;
                if (Event.wheel.y > 0) {
                    Stream << SDL_CUSTOM_WHEELUP;
                } else if (Event.wheel.y < 0) {
                    Stream << SDL_CUSTOM_WHEELDOWN;
                }

                Lua::ExecuteScript(Lua, "Application.OnGlobalEvent(\"KeyDown\", " + Stream.str() + ");");
                Lua::ExecuteScript(Lua, "Application.OnGlobalEvent(\"KeyUp\", " + Stream.str() + ");");
            } else if (Event.type == SDL_JOYDEVICEADDED) {
                SDL_JoystickOpen(Event.jdevice.which);
                //std::cout << "Opened Joystick " << SDL_JoystickInstanceID(Joystick) << " (" << SDL_JoystickNameForIndex(SDL_JoystickInstanceID(Joystick)) << ")" << std::endl;
            } else if (Event.type == SDL_JOYDEVICEREMOVED) {
                //std::cout << "Closed Joystick " << Event.jdevice.which << std::endl;
                SDL_Joystick *Joystick = SDL_JoystickOpen(Event.jdevice.which);
                SDL_JoystickClose(Joystick);
            } else if (Event.type == SDL_QUIT) {
                Stop();
                Input = 1003;
            } else if (Event.type == SDL_WINDOWEVENT) {
                if (Event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    Uint32 Flags = SDL_GetWindowFlags(Window);

                    if (WindowMode == WindowModes::Maximised && !(Flags&SDL_WINDOW_MAXIMIZED)) {
                        WindowMode = WindowModes::Windowed;
                        ApplyVideoMode();

                        //Why is this necessary in only 1 scenario, and can it be added to ApplyVideoMode()?
                        int Width = GetWidth(), Height = GetHeight();

                        Renderer::SetViewport(Width, Height);
                        Renderer::Setup2D(Width, Height);

                        EventQueue.push_back(Events::ResolutionChanged);
                    } else if (WindowMode != WindowModes::Maximised && (Flags&SDL_WINDOW_MAXIMIZED)) {
                        WindowMode = WindowModes::Maximised;
                        ApplyVideoMode();
                    } else {
                        int Width = 0, Height = 0;
                        SDL_GetWindowSize(Window, &Width, &Height);

                        SetResolution(Width, Height);
                        Renderer::SetViewport(Width, Height);
                        Renderer::Setup2D(Width, Height);
                    }

                    Input = 1004;
                }
            }
        }

        return Input;
    }

    /// Checks if the application is running.
    bool State::IsRunning() {
        if (Status) Update();
        return Status;
    }

    /// Saves a screenshot at the specified location.
    /** The filename of the saved screenshot is in the following format: YYYYMMDDHHmmss */
    void State::SaveScreenshot(std::string Location) {
        time_t Now = time(0);
        tm *Date = localtime(&Now);

        int Year = Date->tm_year+1900;
        int Month = Date->tm_mon+1;
        int Day = Date->tm_mday;
        int Hour = Date->tm_hour;
        int Minute = Date->tm_min;
        int Second = Date->tm_sec;

        std::ostringstream Stream;
        Stream << Location << Year;
        if (Month < 10) Stream << "0"; Stream << Month;
        if (Day < 10) Stream << "0"; Stream << Day;
        if (Hour < 10) Stream << "0"; Stream << Hour;
        if (Minute < 10) Stream << "0"; Stream << Minute;
        if (Second < 10) Stream << "0"; Stream << Second << ".bmp";

        if (Renderer::SaveScreenshot(Stream.str())) {
            std::cout << "Saved Screenshot: " << Stream.str() << std::endl;
        }
    }

    /// Converts a specified SDL_Scancode to text.
    /** Used to display different keys in UI menus.
        @param Key The SDL_Scancode to convert to text.
        @param Short When true, certain keys are made shorter, e.g. "Bkspc" is short for "Backspace". */
    std::string State::SDLScancodeToText(SDL_Scancode Key, bool Short) {
        std::string Text;

        int IntKey = (int)Key;

        switch(IntKey) {
            case SDL_SCANCODE_UNKNOWN:
                Text = "Unknown";
                break;
            case SDL_SCANCODE_A:
                Text = "A";
                break;
            case SDL_SCANCODE_B:
                Text = "B";
                break;
            case SDL_SCANCODE_C:
                Text = "C";
                break;
            case SDL_SCANCODE_D:
                Text = "D";
                break;
            case SDL_SCANCODE_E:
                Text = "E";
                break;
            case SDL_SCANCODE_F:
                Text = "F";
                break;
            case SDL_SCANCODE_G:
                Text = "G";
                break;
            case SDL_SCANCODE_H:
                Text = "H";
                break;
            case SDL_SCANCODE_I:
                Text = "I";
                break;
            case SDL_SCANCODE_J:
                Text = "J";
                break;
            case SDL_SCANCODE_K:
                Text = "K";
                break;
            case SDL_SCANCODE_L:
                Text = "L";
                break;
            case SDL_SCANCODE_M:
                Text = "M";
                break;
            case SDL_SCANCODE_N:
                Text = "N";
                break;
            case SDL_SCANCODE_O:
                Text = "O";
                break;
            case SDL_SCANCODE_P:
                Text = "P";
                break;
            case SDL_SCANCODE_Q:
                Text = "Q";
                break;
            case SDL_SCANCODE_R:
                Text = "R";
                break;
            case SDL_SCANCODE_S:
                Text = "S";
                break;
            case SDL_SCANCODE_T:
                Text = "T";
                break;
            case SDL_SCANCODE_U:
                Text = "U";
                break;
            case SDL_SCANCODE_V:
                Text = "V";
                break;
            case SDL_SCANCODE_W:
                Text = "W";
                break;
            case SDL_SCANCODE_X:
                Text = "X";
                break;
            case SDL_SCANCODE_Y:
                Text = "Y";
                break;
            case SDL_SCANCODE_Z:
                Text = "Z";
                break;
            case SDL_SCANCODE_1:
                Text = "1";
                break;
            case SDL_SCANCODE_2:
                Text = "2";
                break;
            case SDL_SCANCODE_3:
                Text = "3";
                break;
            case SDL_SCANCODE_4:
                Text = "4";
                break;
            case SDL_SCANCODE_5:
                Text = "5";
                break;
            case SDL_SCANCODE_6:
                Text = "6";
                break;
            case SDL_SCANCODE_7:
                Text = "7";
                break;
            case SDL_SCANCODE_8:
                Text = "8";
                break;
            case SDL_SCANCODE_9:
                Text = "9";
                break;
            case SDL_SCANCODE_0:
                Text = "0";
                break;
            case SDL_SCANCODE_RETURN:
                Text = "Enter";
                break;
            case SDL_SCANCODE_ESCAPE:
                Text = "Esc";
                break;
            case SDL_SCANCODE_BACKSPACE:
                if (Short) Text = "Bkspc"; else Text = "Backspace";
                break;
            case SDL_SCANCODE_TAB:
                Text = "Tab";
                break;
            case SDL_SCANCODE_SPACE:
                Text = "Space";
                break;
            case SDL_SCANCODE_MINUS:
                Text = "-";
                break;
            case SDL_SCANCODE_EQUALS:
                Text = "=";
                break;
            case SDL_SCANCODE_LEFTBRACKET:
                Text = "[";
                break;
            case SDL_SCANCODE_RIGHTBRACKET:
                Text = "]";
                break;
            case SDL_SCANCODE_BACKSLASH:
                Text = "\\";
                break;
            case SDL_SCANCODE_SEMICOLON:
                Text = ";";
                break;
            case SDL_SCANCODE_APOSTROPHE:
                Text = "'";
                break;
            case SDL_SCANCODE_GRAVE:
                Text = "`";
                break;
            case SDL_SCANCODE_COMMA:
                Text = ",";
                break;
            case SDL_SCANCODE_PERIOD:
                Text = ".";
                break;
            case SDL_SCANCODE_SLASH:
                Text = "/";
                break;
            case SDL_SCANCODE_CAPSLOCK:
                if (Short) Text = "CpsLk"; else Text = "Caps Lock";
                break;
            case SDL_SCANCODE_F1:
                Text = "F1";
                break;
            case SDL_SCANCODE_F2:
                Text = "F2";
                break;
            case SDL_SCANCODE_F3:
                Text = "F3";
                break;
            case SDL_SCANCODE_F4:
                Text = "F4";
                break;
            case SDL_SCANCODE_F5:
                Text = "F5";
                break;
            case SDL_SCANCODE_F6:
                Text = "F6";
                break;
            case SDL_SCANCODE_F7:
                Text = "F7";
                break;
            case SDL_SCANCODE_F8:
                Text = "F8";
                break;
            case SDL_SCANCODE_F9:
                Text = "F9";
                break;
            case SDL_SCANCODE_F10:
                Text = "F10";
                break;
            case SDL_SCANCODE_F11:
                Text = "F11";
                break;
            case SDL_SCANCODE_F12:
                Text = "F12";
                break;
            case SDL_SCANCODE_PRINTSCREEN:
                if (Short) Text = "PrtScn"; else Text = "Print Screen";
                break;
            case SDL_SCANCODE_SCROLLLOCK:
                if (Short) Text = "ScrLk"; else Text = "Scroll Lock";
                break;
            case SDL_SCANCODE_PAUSE:
                Text = "Pause";
                break;
            case SDL_SCANCODE_INSERT:
                if (Short) Text = "Ins"; else Text = "Insert";
                break;
            case SDL_SCANCODE_HOME:
                Text = "Home";
                break;
            case SDL_SCANCODE_PAGEUP:
                if (Short) Text = "PgUp"; else Text = "Page Up";
                break;
            case SDL_SCANCODE_DELETE:
                if (Short) Text = "Del"; else Text = "Delete";
                break;
            case SDL_SCANCODE_END:
                Text = "End";
                break;
            case SDL_SCANCODE_PAGEDOWN:
                if (Short) Text = "PgDn"; else Text = "Page Down";
                break;
            case SDL_SCANCODE_RIGHT:
                Text = "Right";
                break;
            case SDL_SCANCODE_LEFT:
                Text = "Left";
                break;
            case SDL_SCANCODE_DOWN:
                Text = "Down";
                break;
            case SDL_SCANCODE_UP:
                Text = "Up";
                break;
            case SDL_SCANCODE_NUMLOCKCLEAR:
                if (Short) Text = "NmLk"; else Text = "Num Lock";
                break;
            case SDL_SCANCODE_KP_DIVIDE:
                if (Short) Text = "KP /"; else Text = "Keypad /";
                break;
            case SDL_SCANCODE_KP_MULTIPLY:
                if (Short) Text = "KP *"; else Text = "Keypad *";
                break;
            case SDL_SCANCODE_KP_MINUS:
                if (Short) Text = "KP -"; else Text = "Keypad -";
                break;
            case SDL_SCANCODE_KP_PLUS:
                if (Short) Text = "KP +"; else Text = "Keypad +";
                break;
            case SDL_SCANCODE_KP_ENTER:
                if (Short) Text = "KP Enter"; else Text = "Keypad Enter";
                break;
            case SDL_SCANCODE_KP_1:
                if (Short) Text = "KP1"; else Text = "Keypad 1";
                break;
            case SDL_SCANCODE_KP_2:
                if (Short) Text = "KP2"; else Text = "Keypad 2";
                break;
            case SDL_SCANCODE_KP_3:
                if (Short) Text = "KP3"; else Text = "Keypad 3";
                break;
            case SDL_SCANCODE_KP_4:
                if (Short) Text = "KP4"; else Text = "Keypad 4";
                break;
            case SDL_SCANCODE_KP_5:
                if (Short) Text = "KP5"; else Text = "Keypad 5";
                break;
            case SDL_SCANCODE_KP_6:
                if (Short) Text = "KP6"; else Text = "Keypad 6";
                break;
            case SDL_SCANCODE_KP_7:
                if (Short) Text = "KP7"; else Text = "Keypad 7";
                break;
            case SDL_SCANCODE_KP_8:
                if (Short) Text = "KP8"; else Text = "Keypad 8";
                break;
            case SDL_SCANCODE_KP_9:
                if (Short) Text = "KP9"; else Text = "Keypad 9";
                break;
            case SDL_SCANCODE_KP_0:
                if (Short) Text = "KP0"; else Text = "Keypad 0";
                break;
            case SDL_SCANCODE_KP_PERIOD:
                if (Short) Text = "KP ."; else Text = "Keypad .";
                break;
            case SDL_SCANCODE_NONUSBACKSLASH:
                Text = "\\";
                break;
            case SDL_SCANCODE_APPLICATION:
                Text = "Menu";
                break;
            case SDL_SCANCODE_POWER:
                if (Short) Text = "Pwr"; else Text = "Power";
                break;
            case SDL_SCANCODE_KP_EQUALS:
                if (Short) Text = "KP ="; else Text = "Keypad =";
                break;
            case SDL_SCANCODE_F13:
                Text = "F13";
                break;
            case SDL_SCANCODE_F14:
                Text = "F14";
                break;
            case SDL_SCANCODE_F15:
                Text = "F15";
                break;
            case SDL_SCANCODE_F16:
                Text = "F16";
                break;
            case SDL_SCANCODE_F17:
                Text = "F17";
                break;
            case SDL_SCANCODE_F18:
                Text = "F18";
                break;
            case SDL_SCANCODE_F19:
                Text = "F19";
                break;
            case SDL_SCANCODE_F20:
                Text = "F20";
                break;
            case SDL_SCANCODE_F21:
                Text = "F21";
                break;
            case SDL_SCANCODE_F22:
                Text = "F22";
                break;
            case SDL_SCANCODE_F23:
                Text = "F23";
                break;
            case SDL_SCANCODE_F24:
                Text = "F24";
                break;
            case SDL_SCANCODE_EXECUTE:
                if (Short) Text = "Exec"; else Text = "Execute";
                break;
            case SDL_SCANCODE_HELP:
                Text = "Help";
                break;
            case SDL_SCANCODE_MENU:
                Text = "Menu";
                break;
            case SDL_SCANCODE_SELECT:
                if (Short) Text = "Sel"; else Text = "Select";
                break;
            case SDL_SCANCODE_STOP:
                Text = "Stop";
                break;
            case SDL_SCANCODE_AGAIN:
                if (Short) Text = "Re"; else Text = "Redo";
                break;
            case SDL_SCANCODE_CUT:
                Text = "Cut";
                break;
            case SDL_SCANCODE_COPY:
                Text = "Copy";
                break;
            case SDL_SCANCODE_PASTE:
                Text = "Paste";
                break;
            case SDL_SCANCODE_FIND:
                Text = "Find";
                break;
            case SDL_SCANCODE_MUTE:
                Text = "Mute";
                break;
            case SDL_SCANCODE_VOLUMEUP:
                if (Short) Text = "VolUp"; else Text = "Volume Up";
                break;
            case SDL_SCANCODE_VOLUMEDOWN:
                if (Short) Text = "VolDn"; else Text = "Volume Down";
                break;
/* not sure whether there's a reason to enable these */
/*     SDL_SCANCODE_LOCKINGCAPSLOCK = 130,  */
/*     SDL_SCANCODE_LOCKINGNUMLOCK = 131, */
/*     SDL_SCANCODE_LOCKINGSCROLLLOCK = 132, */

            case SDL_SCANCODE_KP_COMMA:
                if (Short) Text = "KP ,"; else Text = "Keypad ,";
                break;
            case SDL_SCANCODE_KP_EQUALSAS400:
                if (Short) Text = "KP ="; else Text = "Keypad =";
                break;
            case SDL_SCANCODE_INTERNATIONAL1:
                if (Short) Text = "INT1"; else Text = "Intl 1";
                break;
            case SDL_SCANCODE_INTERNATIONAL2:
                if (Short) Text = "INT2"; else Text = "Intl 2";
                break;
            case SDL_SCANCODE_INTERNATIONAL3:
                Text = "Yen";
                break;
            case SDL_SCANCODE_INTERNATIONAL4:
                if (Short) Text = "INT4"; else Text = "Intl 4";
                break;
            case SDL_SCANCODE_INTERNATIONAL5:
                if (Short) Text = "INT5"; else Text = "Intl 5";
                break;
            case SDL_SCANCODE_INTERNATIONAL6:
                if (Short) Text = "INT6"; else Text = "Intl 6";
                break;
            case SDL_SCANCODE_INTERNATIONAL7:
                if (Short) Text = "INT7"; else Text = "Intl 7";
                break;
            case SDL_SCANCODE_INTERNATIONAL8:
                if (Short) Text = "INT8"; else Text = "Intl 8";
                break;
            case SDL_SCANCODE_INTERNATIONAL9:
                if (Short) Text = "INT9"; else Text = "Intl 9";
                break;
            case SDL_SCANCODE_LANG1:
                Text = "Ha/En";
                break;
            case SDL_SCANCODE_LANG2:
                if (Short) Text = "Hj"; else Text = "Hanja";
                break;
            case SDL_SCANCODE_LANG3:
                if (Short) Text = "Kt"; else Text = "Katakana";
                break;
            case SDL_SCANCODE_LANG4:
                if (Short) Text = "Hr"; else Text = "Hiragana";
                break;
            case SDL_SCANCODE_LANG5:
                if (Short) Text = "Ze/Ha"; else Text = "Zenkaku/Hankaku";
                break;
/* reserved
    SDL_SCANCODE_LANG6 = 149,
    SDL_SCANCODE_LANG7 = 150,
    SDL_SCANCODE_LANG8 = 151,
    SDL_SCANCODE_LANG9 = 152,
*/
            case SDL_SCANCODE_ALTERASE:
                if (Short) Text = "EE"; else Text = "Erase-Eaze";
                break;
            case SDL_SCANCODE_SYSREQ:
                Text = "SysRq";
                break;
            case SDL_SCANCODE_CANCEL:
                Text = "Cancel";
                break;
            case SDL_SCANCODE_CLEAR:
                Text = "Clear";
                break;
            case SDL_SCANCODE_PRIOR:
                Text = "Prior";
                break;
            case SDL_SCANCODE_RETURN2:
                Text = "Return 2";
                break;
            case SDL_SCANCODE_SEPARATOR:
                if (Short) Text = "Sep"; else Text = "Separator";
                break;
            case SDL_SCANCODE_OUT:
                Text = "Out";
                break;
            case SDL_SCANCODE_OPER:
                Text = "Oper";
                break;
            case SDL_SCANCODE_CLEARAGAIN:
                if (Short) Text = "ClrAgn"; else Text = "Clear Again";
                break;
            case SDL_SCANCODE_CRSEL:
                Text = "CrSel";
                break;
            case SDL_SCANCODE_EXSEL:
                Text = "ExSel";
                break;
/* more keypad keys
    SDL_SCANCODE_KP_00 = 176,
    SDL_SCANCODE_KP_000 = 177,
    SDL_SCANCODE_THOUSANDSSEPARATOR = 178,
    SDL_SCANCODE_DECIMALSEPARATOR = 179,
    SDL_SCANCODE_CURRENCYUNIT = 180,
    SDL_SCANCODE_CURRENCYSUBUNIT = 181,
    SDL_SCANCODE_KP_LEFTPAREN = 182,
    SDL_SCANCODE_KP_RIGHTPAREN = 183,
    SDL_SCANCODE_KP_LEFTBRACE = 184,
    SDL_SCANCODE_KP_RIGHTBRACE = 185,
    SDL_SCANCODE_KP_TAB = 186,
    SDL_SCANCODE_KP_BACKSPACE = 187,
    SDL_SCANCODE_KP_A = 188,
    SDL_SCANCODE_KP_B = 189,
    SDL_SCANCODE_KP_C = 190,
    SDL_SCANCODE_KP_D = 191,
    SDL_SCANCODE_KP_E = 192,
    SDL_SCANCODE_KP_F = 193,
    SDL_SCANCODE_KP_XOR = 194,
    SDL_SCANCODE_KP_POWER = 195,
    SDL_SCANCODE_KP_PERCENT = 196,
    SDL_SCANCODE_KP_LESS = 197,
    SDL_SCANCODE_KP_GREATER = 198,
    SDL_SCANCODE_KP_AMPERSAND = 199,
    SDL_SCANCODE_KP_DBLAMPERSAND = 200,
    SDL_SCANCODE_KP_VERTICALBAR = 201,
    SDL_SCANCODE_KP_DBLVERTICALBAR = 202,
    SDL_SCANCODE_KP_COLON = 203,
    SDL_SCANCODE_KP_HASH = 204,
    SDL_SCANCODE_KP_SPACE = 205,
    SDL_SCANCODE_KP_AT = 206,
    SDL_SCANCODE_KP_EXCLAM = 207,
    SDL_SCANCODE_KP_MEMSTORE = 208,
    SDL_SCANCODE_KP_MEMRECALL = 209,
    SDL_SCANCODE_KP_MEMCLEAR = 210,
    SDL_SCANCODE_KP_MEMADD = 211,
    SDL_SCANCODE_KP_MEMSUBTRACT = 212,
    SDL_SCANCODE_KP_MEMMULTIPLY = 213,
    SDL_SCANCODE_KP_MEMDIVIDE = 214,
    SDL_SCANCODE_KP_PLUSMINUS = 215,
    SDL_SCANCODE_KP_CLEAR = 216,
    SDL_SCANCODE_KP_CLEARENTRY = 217,
    SDL_SCANCODE_KP_BINARY = 218,
    SDL_SCANCODE_KP_OCTAL = 219,
    SDL_SCANCODE_KP_DECIMAL = 220,
    SDL_SCANCODE_KP_HEXADECIMAL = 221,
*/
            case SDL_SCANCODE_LCTRL:
                if (Short) Text = "LC"; else Text = "L. Ctrl";
                break;
            case SDL_SCANCODE_LSHIFT:
                if (Short) Text = "LS"; else Text = "L. Shift";
                break;
            case SDL_SCANCODE_LALT:
                if (Short) Text = "LA"; else Text = "L. Alt";
                break;
            case SDL_SCANCODE_LGUI:
                if (Short) Text = "LW"; else Text = "L. Win";
                break;
            case SDL_SCANCODE_RCTRL:
                if (Short) Text = "RC"; else Text = "R. Ctrl";
                break;
            case SDL_SCANCODE_RSHIFT:
                if (Short) Text = "RS"; else Text = "R. Shift";
                break;
            case SDL_SCANCODE_RALT:
                if (Short) Text = "RA"; else Text = "R. Alt";
                break;
            case SDL_SCANCODE_RGUI:
                if (Short) Text = "RW"; else Text = "R. Win";
                break;
/* SDL_SCANCODE_MODE = 257, */
            case SDL_SCANCODE_AUDIONEXT:
                if (Short) Text = "Nxt"; else Text = "Next";
                break;
            case SDL_SCANCODE_AUDIOPREV:
                if (Short) Text = "Prev"; else Text = "Previous";
                break;
            case SDL_SCANCODE_AUDIOSTOP:
                Text = "Stop";
                break;
            case SDL_SCANCODE_AUDIOPLAY:
                Text = "Play";
                break;
            case SDL_SCANCODE_AUDIOMUTE:
                Text = "Mute";
                break;
            case SDL_SCANCODE_MEDIASELECT:
                if (Short) Text = "Sel"; else Text = "Select";
                break;
            case SDL_SCANCODE_WWW:
                if (Short) Text = "Net"; else Text = "Internet";
                break;
            case SDL_SCANCODE_MAIL:
                Text = "Mail";
                break;
            case SDL_SCANCODE_CALCULATOR:
                if (Short) Text = "Calc"; else Text = "Calculator";
                break;
            case SDL_SCANCODE_COMPUTER:
                if (Short) Text = "PC"; else Text = "Computer";
                break;
            case SDL_SCANCODE_AC_SEARCH:
                Text = "Search";
                break;
            case SDL_SCANCODE_AC_HOME:
                Text = "Home";
                break;
            case SDL_SCANCODE_AC_BACK:
                if (Short) Text = "Bk"; else Text = "Back";
                break;
            case SDL_SCANCODE_AC_FORWARD:
                if (Short) Text = "Fwd"; else Text = "Forward";
                break;
            case SDL_SCANCODE_AC_STOP:
                Text = "Stop";
                break;
            case SDL_SCANCODE_AC_REFRESH:
                Text = "Refresh";
                break;
            case SDL_SCANCODE_AC_BOOKMARKS:
                Text = "Bookmarks";
                break;
            case SDL_SCANCODE_BRIGHTNESSDOWN:
                if (Short) Text = "BrDn"; else Text = "Brightness Down";
                break;
            case SDL_SCANCODE_BRIGHTNESSUP:
                if (Short) Text = "BrUp"; else Text = "Brightness Up";
                break;
            case SDL_SCANCODE_DISPLAYSWITCH:
                if (Short) Text = "DS"; else Text = "Display Switch";
                break;
            case SDL_SCANCODE_KBDILLUMTOGGLE:
                if (Short) Text = "TL"; else Text = "Toggle Lights";
                break;
            case SDL_SCANCODE_KBDILLUMDOWN:
                if (Short) Text = "DL"; else Text = "Dim Lights";
                break;
            case SDL_SCANCODE_KBDILLUMUP:
                if (Short) Text = "BL"; else Text = "Brighten Lights";
                break;
            case SDL_SCANCODE_EJECT:
                if (Short) Text = "Ejt"; else Text = "Eject";
                break;
            case SDL_SCANCODE_SLEEP:
                Text = "Sleep";
                break;
            case SDL_SCANCODE_APP1:
                if (Short) Text = "APP1"; else Text = "App. 1";
                break;
            case SDL_SCANCODE_APP2:
                if (Short) Text = "APP2"; else Text = "App. 2";
                break;
            case SDL_CUSTOM_CTRL:
                if (Short) Text = "C"; else Text = "Ctrl";
                break;
            case SDL_CUSTOM_SHIFT:
                if (Short) Text = "S"; else Text = "Shift";
                break;
            case SDL_CUSTOM_ALT:
                if (Short) Text = "A"; else Text = "Alt";
                break;
            case SDL_CUSTOM_LMB:
                if (Short) Text = "LMB"; else Text = "Left Mouse Button";
                break;
            case SDL_CUSTOM_RMB:
                if (Short) Text = "RMB"; else Text = "Right Mouse Button";
                break;
            case SDL_CUSTOM_MMB:
                if (Short) Text = "MB3"; else Text = "Mouse Button 3";
                break;
            case SDL_CUSTOM_X1MB:
                if (Short) Text = "MB4"; else Text = "Mouse Button 4";
                break;
            case SDL_CUSTOM_X2MB:
                if (Short) Text = "MB5"; else Text = "Mouse Button 5";
                break;
            case SDL_CUSTOM_WHEELDOWN:
                if (Short) Text = "MWDn"; else Text = "Mouse Wheel Down";
                break;
            case SDL_CUSTOM_WHEELUP:
                if (Short) Text = "MWUp"; else Text = "Mouse Wheel Up";
                break;
            default:
                {
                    std::ostringstream Stream;
                    Stream << Key;
                    Text = "#" + Stream.str();
                    break;
                }
                break;
        }

        return Text;
    }

    /// Sets the display of the application window.
    void State::SetDisplayIndex(int DisplayIndex) {
        if (DisplayIndex >= 0) this->DisplayIndex = DisplayIndex;
    }

    /// Sets the icon of the application window.
    void State::SetIcon(std::string Icon) {
        this->Icon = Icon;
        if (Window && Icon != "") {
            SDL_Surface *Surface = Renderer::LoadImage(Icon);
            if (Surface)
                SDL_SetWindowIcon(Window, Surface);
            else std::cerr << "(Application/State.cpp) SetIcon(): Failed to load application icon." << std::endl;
        }
    }

    /// Sets the maximum allowed inputs per second.
    void State::SetIPS(int IPS) {
        this->IPS = IPS;
    }

    /// Positions the window at the specified coordinates.
    void State::SetPosition(int X, int Y) {
        if (Window) SDL_SetWindowPosition(Window, X, Y);
    }

    /// Sets the intended process speed for the application.
    void State::SetPPS(int PPS, int MaximumRenderSkips) {
        this->PPS = PPS;
        this->MaximumRenderSkips = MaximumRenderSkips;
    }

    /// Sets the width and height of the application.
    /** @param Width, Height The specified resolution.
        @param WindowMode The window mode for which the resolution is intended. If not specified, the current window mode is used. */
    void State::SetResolution(int Width, int Height, int WindowMode) {
        if (WindowMode < 0) WindowMode = this->WindowMode;

        if (WindowMode == WindowModes::Windowed) {
            if (this->WindowMode == WindowMode && (Width != WindowedResolution.X() || Height != WindowedResolution.Y())) EventQueue.push_back(Events::ResolutionChanged);
            WindowedResolution = Vector2(Width, Height);
        } else if (WindowMode == WindowModes::Fullscreen) {
            if (this->WindowMode == WindowMode && (Width != FullscreenResolution.X() || Height != FullscreenResolution.Y())) EventQueue.push_back(Events::ResolutionChanged);
            PreviousFullscreenResolution = Vector2(FullscreenResolution.X(), FullscreenResolution.Y());
            FullscreenResolution = Vector2(Width, Height);
        } //else std::cerr << "(Application/State.cpp) SetResolution(): Function has no effect in current WindowMode." << std::endl;
    }

    /// Sets the title of the window application.
    void State::SetTitle(std::string Title) {
        this->Title = Title;
    }

    /// Enables of disables various application information from being included on the window title.
    void State::SetTitleStats(bool State) {
        TitleStats = State;
    }

    /// Sets the VSync option.
    void State::SetVSync(bool VSync) {
        this->VSync = VSync;
    }

    /// Sets the window mode of the application.
    void State::SetWindowMode(int WindowMode) {
        if (WindowMode == WindowModes::Borderless) Bordered = false; else Bordered = true;
        this->WindowMode = WindowMode;
    }

    /// Shows the application window.
    void State::Show() {
        if (Window) {
            SDL_ShowWindow(Window);
        }
    }

    /// Enables or disables the border of the application window.
    void State::ShowBorder(bool State) {
        Bordered = State;
    }

    /// Basic constructor.
    /** @param Lua Used to set the Lua context for the API implementation.
        @param Title, Icon Used to initialise the title and icon of the application window.
        @param Width, Height Used to initialise the resolution of the application window. */
    State::State(lua_State *Lua, std::string Title, std::string Icon, int Width, int Height) {
        Window = NULL;

        Status = false;
        LastUpdate = NextInput = NextProcess = 0;
        TitleStats = true;
        VSync = false;
        CurrentIPS = CurrentPPS = DisplayIndex = FrameCount = Framerate = InputCount = MaximumRenderSkips = ProcessCount = RenderSkips = WindowMode = 0; PPS = IPS = 30;

        this->Lua = Lua;
        this->Title = Title;
        this->Icon = Icon;
        WindowedResolution = Vector2(Width, Height);
        this->Resizable = false;
        this->Bordered = true;
    }

    /// Used to start the application.
    /** @param Flags Set of flags used to initialise the application.
        @param D 2 for 2D, 3 for 3D.
        @param DisplayIndex Index of the display to use. */
    bool State::Start(Uint32 Flags, unsigned int D, int DisplayIndex) {
        if (!Status) {
            Uint32 WindowFlags = SDL_WINDOW_SHOWN|SDL_WINDOW_INPUT_FOCUS|SDL_WINDOW_MOUSE_FOCUS|SDL_WINDOW_OPENGL;
            if (WindowMode == WindowModes::Fullscreen) {
                WindowFlags |= SDL_WINDOW_FULLSCREEN;
            } else if (WindowMode == WindowModes::Maximised) {
                WindowFlags |= SDL_WINDOW_MAXIMIZED;
                WindowFlags |= SDL_WINDOW_RESIZABLE;
            } else {
                if (Resizable) WindowFlags |= SDL_WINDOW_RESIZABLE;
                if (!Bordered) WindowFlags |= SDL_WINDOW_BORDERLESS;
            }

            if (SDL_Init(Flags) == 0) {
                if (DisplayIndex < 0) DisplayIndex = this->DisplayIndex;

                if (DisplayIndex >= SDL_GetNumVideoDisplays()) {
                    std::cerr << "(Application/State.cpp) SetDisplayIndex: Invalid DisplayIndex set (" << DisplayIndex << ")." << std::endl;
                    DisplayIndex = 0;
                }

                this->DisplayIndex = DisplayIndex;

                Window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex), SDL_WINDOWPOS_CENTERED_DISPLAY(DisplayIndex), GetWidth(), GetHeight(), WindowFlags);

                if (Window) {
                    GLContext = SDL_GL_CreateContext(Window);
                    if (GLContext) {
                        if (D == 2) {
                            Renderer::Setup2D(GetWidth(), GetHeight());
                        } else if (D == 3) {
                            Renderer::Setup3D(GetWidth(), GetHeight());
                        } else std::cerr << "(Application/State.cpp) Start(): Invalid renderer setup (" << D << "D)." << std::endl;
                    } else std::cerr << "(Application/State.cpp) Start(): Unable to create GLContext. " << SDL_GetError() << "." << std::endl;

                    Status = true;
                    SetIcon(Icon);
                } else std::cerr << "(Application/State.cpp) Start(): Unable to create window. " << SDL_GetError() << "." << std::endl;
            } else std::cerr << "(Application/State.cpp) Start(): SDL video initialization failed. " << SDL_GetError() << "." << std::endl;
        } else std::cerr << "(Application/State.cpp) Start(): Application is already running." << std::endl;

        return Status;
    }

    /// Stops the application from running.
    /** This function does not close the application window. */
    void State::Stop() {
        Status = false;
    }

    /// Used internally to update the various counters of the application and the window title.
    void State::Update() {
        if (Window) {
            SDL_GL_SwapWindow(Window);
            Renderer::Clear();

            ++FrameCount;
            if (GetRuntime()-LastUpdate >= 1) {
                LastUpdate = GetRuntime();
                Framerate = FrameCount;
                FrameCount = 0;

                CurrentPPS = ProcessCount;
                ProcessCount = 0;

                CurrentIPS = InputCount;
                InputCount = 0;

                if (Bordered && TitleStats) {
                    std::ostringstream Stream;
                    Stream << Title << " | IPS: " << CurrentIPS << " | PPS: " << CurrentPPS << " | FPS: " << GetFramerate() << " |";
                    SDL_SetWindowTitle(Window, Stream.str().c_str());
                }
            }

            RenderSkips = 0;
        }
    }

    /// Basic destructor.
    State::~State() {
        Window = NULL;

        Bordered = Resizable = Status = TitleStats = VSync = false;
        LastUpdate = NextInput = NextProcess = 0;
        CurrentIPS = CurrentPPS = DisplayIndex = FrameCount = Framerate = MaximumRenderSkips = InputCount = IPS = PPS = ProcessCount = RenderSkips = WindowMode = 0;
    }
}
