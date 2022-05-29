//State.h
#ifndef NEOAPP_STATE_H
#define NEOAPP_STATE_H

#include <AtUtility/Vector2.h>
#include <Lua/lua.hpp>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>

using namespace AtUtility;

/// Contains all class and function implementations of the project.
namespace AtApp {
    /// Used to enumerate different Window modes.
    namespace WindowModes {
        static const int Windowed = 0;
        static const int Fullscreen = 1;
        static const int Borderless = 2;
        static const int Maximised = 3;
    }

    /// Used to enumerate different application events.
    namespace Events {
        static const int ResolutionChanged       = 3000;
    }

	/// Used to setup, load, and manage the application window.
    class State {
        //Members
        protected:
            bool Bordered;                              //!< Determines if the application window will have a border.
            bool Resizable;                             //!< Determines if the application window is resizable.
            bool Status;                                //!< Set to true if the application is running.
            bool TitleStats;                            //!< Determines if information about the application is shown as the window title.
            bool VSync;                                 //!< Determines the VSync property of the application.
            float LastUpdate;                           //!< Timestamp of the last known application update.
            float NextInput;                            //!< Timestamp for the next earliest accepted input to the application.
            float NextProcess;                          //!< Timestamp for the next intended application process loop.
            int CurrentIPS;                             //!< Last known measurement of 'inputs per second'.
            int CurrentPPS;                             //!< Last known measurement of 'processes per second'.
            int DisplayIndex;                           //!< Index of the display used for the application window.
            int FrameCount;                             //!< Frame counter used to measure framerate.
            int Framerate;                              //!< Last known measurement of the application framerate.
            int InputCount;                             //!< Input counter used to measure 'inputs per second'.
            int IPS;                                    //!< Maximum allowed 'inputs per second'.
            int MaximumRenderSkips;                     //!< Maximum allowed process loops between rendered frames.
            int PPS;                                    //!< Target 'processes per second'.
            int ProcessCount;                           //!< Process loop counter used to measure 'processes per second'.
            int RenderSkips;                            //!< Render skip counter used to measure process loops between rendered frames.
            int WindowMode;                             //!< Window mode set for the application window.
            lua_State *Lua;                             //!< Lua context for the Lua API.
            Vector2 FullscreenResolution;               //!< Set fullscreen resolution.
            Vector2 PreviousFullscreenResolution;       //!< Last known fullscreen resolution.
            Vector2 WindowedResolution;                 //!< Set windowed resolution.
            SDL_GLContext GLContext;                    //!< GLContext used for rendering.
            SDL_Window *Window;                         //!< Created SDL_Window instance.
            std::string Icon;                           //!< Path to the application icon.
            std::string Title;                          //!< Application title.
            std::vector<int> EventQueue;                //!< Event stack to process input events.
        //Access Methods
        public:
            State(lua_State *Lua, std::string Title = "", std::string Icon = "", int Width = 0, int Height = 0);
            ~State();
            int GetAvailableVideoModes();
            int GetDisplayIndex();
            int GetFramerate();
            int GetHeight(int WindowMode = -1);
            float GetInterpolation();
            int GetIPS();
            int GetPPS();
            int IsKeyPressed(SDL_Scancode Key);
            float GetRuntime();
            std::string GetVideoMode(int i);
            bool GetVSync();
            int GetWidth(int WindowMode = -1);
            int GetWindowMode();
            bool IsRunning();
            std::string SDLScancodeToText(SDL_Scancode Key, bool Short = false);
        protected:
            float GetInputTimeStep();
            float GetProcessTimeStep();
        //Process Methods
        public:
            void AllowResize(bool State);
            void ApplyVideoMode();
            bool CanInput();
            bool CanProcess();
            void Close();
            void Hide();
            int Input(SDL_Event &Event);
            void SaveScreenshot(std::string Location);
            void SetDisplayIndex(int DisplayIndex);
            void SetIcon(std::string Icon);
            void SetIPS(int IPS);
            void SetPosition(int X, int Y);
            void SetPPS(int PPS, int MaximumRenderSkips);
            void SetResolution(int Width, int Height, int WindowMode = -1);
            void SetTitle(std::string Title);
            void SetTitleStats(bool State);
            void SetVSync(bool VSync);
            void SetWindowMode(int WindowMode);
            void Show();
            void ShowBorder(bool State);
            bool Start(Uint32 Flags, unsigned int D = 2, int DisplayIndex = -1);
            void Stop();
        protected:
            void Update();
    };
}

#endif
