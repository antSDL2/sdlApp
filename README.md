# AtApp

C++ Library used to setup, create, and control an application window. Many features are implemented using functionality of the SDL2 external library. The created instance supports OpenGL for rendering.

## Classes
- **State:** Manager class used to create and manipulate the application window.
- **API:** API exposing many of the methods defined in the library to a Lua environment. Allows run-time interaction and manipulation of the application using scripts written in Lua.

## Dependencies
- Lua 5.2 binding library (lua52)
- SDL2 base (SDL2)
- [AtUtility](https://github.com/atrapalis/AtUtility "AtUtility GitHub repository")
