//State.h
#ifndef NEOAPP_STATE_H
#define NEOAPP_STATE_H

#include <AtPhys/Vector2.h>
#include <Lua/lua.hpp>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>

namespace AtApp {
    namespace WindowModes {
        static const int Windowed = 0;
        static const int Fullscreen = 1;
        static const int Borderless = 2;
        static const int Maximised = 3;
    }

    namespace Events {
        static const int ResolutionChanged       = 3000;
    }

    class State {
        //Members
        protected:
            bool Bordered, Resizable, Status, TitleStats, VSync;
            float LastUpdate, NextInput, NextProcess;
            int CurrentIPS, CurrentPPS, DisplayIndex, FrameCount, Framerate, InputCount, IPS, MaximumRenderSkips, PPS, ProcessCount, RenderSkips, WindowMode;
            lua_State *Lua;
            AtPhys::Vector2 FullscreenResolution, PreviousFullscreenResolution, WindowedResolution;
            SDL_GLContext GLContext;
            SDL_Window *Window;
            std::string Icon, Title;
            std::vector<int> EventQueue;
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
