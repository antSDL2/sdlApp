 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`AtApp`](#namespace_at_app) | Contains all class and function implementations of the project.

# namespace AtApp 

Contains all class and function implementations of the project.

## AtApp Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AtApp::API`](#class_at_app_1_1_a_p_i) | Used to define, implement, and load a Lua [API](#class_at_app_1_1_a_p_i) for the [AtApp::State](#class_at_app_1_1_state) class.
`class `[`AtApp::State`](#class_at_app_1_1_state) | Used to setup, load, and manage the application window.

# class AtApp::API 

Used to define, implement, and load a Lua [API](#class_at_app_1_1_a_p_i) for the [AtApp::State](#class_at_app_1_1_state) class.

In addition to [API](#class_at_app_1_1_a_p_i) handles for the [AtApp::State](#class_at_app_1_1_state) class, this class implements various globals, such as the entire SDL_Scancode enum, global events, and related functions. The object 'Application' is used to call methods of [AtApp::State](#class_at_app_1_1_state) in Lua scripts, e.g. Application:[GetFramerate()](#class_at_app_1_1_a_p_i_1af4be4ff26ac625944f5e3b15736fb220);

## AtApp::API Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`protected  `[`API`](#class_at_app_1_1_a_p_i_1af05837f74706b3b2d3fa2e51f7b5bd42)`()` | Basic constructor.
`protected  `[`~API`](#class_at_app_1_1_a_p_i_1a75ff31443826897e761cd3151a614415)`()` | Basic destructor.

## AtApp::API Members

#### `protected  `[`API`](#class_at_app_1_1_a_p_i_1af05837f74706b3b2d3fa2e51f7b5bd42)`()` 

Basic constructor.

#### `protected  `[`~API`](#class_at_app_1_1_a_p_i_1a75ff31443826897e761cd3151a614415)`()` 

Basic destructor.

# class AtApp::State 

Used to setup, load, and manage the application window.

## AtApp::State Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`State`](#class_at_app_1_1_state_1a8b85ab3f0709f78d3031724a90fae542)`(lua_State * Lua,std::string Title,std::string Icon,int Width,int Height)` | Basic constructor.
`public  `[`~State`](#class_at_app_1_1_state_1aea9467d7e935d4783ee127555ae95b19)`()` | Basic destructor.
`public int `[`GetAvailableVideoModes`](#class_at_app_1_1_state_1aa82868153cde0db0dda21c2a39bf8b01)`()` | Returns the number of permitted display modes.
`public int `[`GetDisplayIndex`](#class_at_app_1_1_state_1a4db320076857fdbf7e9ec425b2056c02)`()` | Returns the index of the display the application is assigned to.
`public int `[`GetFramerate`](#class_at_app_1_1_state_1ac64f74ada37dcfff442f41d5dafae490)`()` | Returns the framerate of the application.
`public int `[`GetHeight`](#class_at_app_1_1_state_1af5baea0569c3b1d5383c99b676b0126b)`(int WindowMode)` | Returns the height of the application window.
`public float `[`GetInterpolation`](#class_at_app_1_1_state_1a55c2a10a633bca3e5d177e27eb384926)`()` | Returns a value which may be used to interpolate the position of objects during rendering.
`public int `[`GetIPS`](#class_at_app_1_1_state_1ae301bb573831d3f2995d59c1629df61e)`()` | Returns the maximum allowed rate of input events.
`public int `[`GetPPS`](#class_at_app_1_1_state_1ab1167564a728d2f59f19c5599b43cb69)`()` | Returns the process speed of the main game loop.
`public int `[`IsKeyPressed`](#class_at_app_1_1_state_1a9387910129e9dcac1f961f676e56b28d)`(SDL_Scancode Key)` | Used to check if a specified key is pressed.
`public float `[`GetRuntime`](#class_at_app_1_1_state_1afc1b2159490b7d6c7c97c9ec8d664bd9)`()` | Returns the current runtime of the application in seconds.
`public std::string `[`GetVideoMode`](#class_at_app_1_1_state_1a539d51d23e4d98f184e5441901ddd980)`(int i)` | Returns the video mode at the specified index.
`public bool `[`GetVSync`](#class_at_app_1_1_state_1a31e00b950f2d863bd4b1041874da0914)`()` | Returns the VSync property.
`public int `[`GetWidth`](#class_at_app_1_1_state_1a575a7c9650a9c9a0449a2ac0da30bda0)`(int WindowMode)` | Returns the width of the application window.
`public int `[`GetWindowMode`](#class_at_app_1_1_state_1ac11f0e6199246cd0615bb11d35d7ec0a)`()` | Returns the WindowMode property.
`public bool `[`IsRunning`](#class_at_app_1_1_state_1a8c05eb01b5d320ddab35300600d6a377)`()` | Checks if the application is running.
`public std::string `[`SDLScancodeToText`](#class_at_app_1_1_state_1acc477600727d108db31d7d806f9da91a)`(SDL_Scancode Key,bool Short)` | Converts a specified SDL_Scancode to text.
`public void `[`AllowResize`](#class_at_app_1_1_state_1a02c5c5f070ab92a463989dc5064a0f8f)`(bool State)` | Enables or disables resizing of the application window.
`public void `[`ApplyVideoMode`](#class_at_app_1_1_state_1a1b625b7ba2b34e5a0c3dd9494b2b22c6)`()` | Applies current video mode settings.
`public bool `[`CanInput`](#class_at_app_1_1_state_1a74f542d5740fbcf5c94fbf3f183215e9)`()` | Checks if input is allowed.
`public bool `[`CanProcess`](#class_at_app_1_1_state_1af106eb246cc84a7ff472bdae5a661e9f)`()` | Checks if the application is allowed to complete a process loop.
`public void `[`Close`](#class_at_app_1_1_state_1afadc1544eddf5e7ffe5afcaa1c2b380a)`()` | Closes the application window.
`public void `[`Hide`](#class_at_app_1_1_state_1af8c2c62e8a5a1194997d71db5572398e)`()` | Hides the application window.
`public int `[`Input`](#class_at_app_1_1_state_1a3b0d6ad1c8fb3d9c3f41a1dc354bb79e)`(SDL_Event & Event)` | Used to handle all SDL input events.
`public void `[`SaveScreenshot`](#class_at_app_1_1_state_1a6c7f845bc99b0eb80ceda303ff191109)`(std::string Location)` | Saves a screenshot at the specified location.
`public void `[`SetDisplayIndex`](#class_at_app_1_1_state_1a8b839c61a206eba7744e2367d6592278)`(int DisplayIndex)` | Sets the display of the application window.
`public void `[`SetIcon`](#class_at_app_1_1_state_1afb020410cbb25598a420b00bbd21fbf4)`(std::string Icon)` | Sets the icon of the application window.
`public void `[`SetIPS`](#class_at_app_1_1_state_1a751ac97dba347e47de76f0274d82a6db)`(int IPS)` | Sets the maximum allowed inputs per second.
`public void `[`SetPosition`](#class_at_app_1_1_state_1a5eecef13b026316676045d9be5a2ab26)`(int X,int Y)` | Positions the window at the specified coordinates.
`public void `[`SetPPS`](#class_at_app_1_1_state_1a3c9e9e3266fb0520b74518ecd68209ba)`(int PPS,int MaximumRenderSkips)` | Sets the intended process speed for the application.
`public void `[`SetResolution`](#class_at_app_1_1_state_1a4f6c9b2eba0dee0c8ace97f820b2f607)`(int Width,int Height,int WindowMode)` | Sets the width and height of the application.
`public void `[`SetTitle`](#class_at_app_1_1_state_1afabfd3224811a0b04c7fcc41100d17e4)`(std::string Title)` | Sets the title of the window application.
`public void `[`SetTitleStats`](#class_at_app_1_1_state_1ae3ea011f2ef6aad9fb055232f5cce72a)`(bool State)` | Enables of disables various application information from being included on the window title.
`public void `[`SetVSync`](#class_at_app_1_1_state_1a1a9006d8525966b016df321fa227c6db)`(bool VSync)` | Sets the VSync option.
`public void `[`SetWindowMode`](#class_at_app_1_1_state_1af8a0b611006c5d592d4d4154282e098e)`(int WindowMode)` | Sets the window mode of the application.
`public void `[`Show`](#class_at_app_1_1_state_1a3e6676f18d78d4cebcdaa5326b9fa543)`()` | Shows the application window.
`public void `[`ShowBorder`](#class_at_app_1_1_state_1aa9084adf92583e0f828d38668de6afa3)`(bool State)` | Enables or disables the border of the application window.
`public bool `[`Start`](#class_at_app_1_1_state_1ab822dfe0ea819650cf9a78bd10d2e01f)`(Uint32 Flags,unsigned int D,int DisplayIndex)` | Used to start the application.
`public void `[`Stop`](#class_at_app_1_1_state_1afcc60ccf076ffbc27c8fff104fe63f8a)`()` | Stops the application from running.
`protected bool `[`Bordered`](#class_at_app_1_1_state_1ab384e8cb2d5f48ac6863e88be38b746d) | Determines if the application window will have a border.
`protected bool `[`Resizable`](#class_at_app_1_1_state_1ac1efcff1acbba2458641b23a189329a0) | Determines if the application window is resizable.
`protected bool `[`Status`](#class_at_app_1_1_state_1ac53a340bd15a7195bdb02eb2b84e56ba) | Set to true if the application is running.
`protected bool `[`TitleStats`](#class_at_app_1_1_state_1a85d93a63a0f563a6988410149bd6745a) | Determines if information about the application is shown as the window title.
`protected bool `[`VSync`](#class_at_app_1_1_state_1aec3d44d2fd71f017d401de7b8fd22c8b) | Determines the VSync property of the application.
`protected float `[`LastUpdate`](#class_at_app_1_1_state_1a7743aaae4242bc3bab4eada530387f00) | Timestamp of the last known application update.
`protected float `[`NextInput`](#class_at_app_1_1_state_1a979036af7e77c79a19e7ff2fca5a35a8) | Timestamp for the next earliest accepted input to the application.
`protected float `[`NextProcess`](#class_at_app_1_1_state_1ae946585e5af8acdb65fd8661b716118b) | Timestamp for the next intended application process loop.
`protected int `[`CurrentIPS`](#class_at_app_1_1_state_1a6a6c5b7f9248e2394160e2063eb07e68) | Last known measurement of 'inputs per second'.
`protected int `[`CurrentPPS`](#class_at_app_1_1_state_1abdba7437312bd5b66b8ed41ea0321d2d) | Last known measurement of 'processes per second'.
`protected int `[`DisplayIndex`](#class_at_app_1_1_state_1ac47717b9901f80725733dc4c7ea08b8d) | Index of the display used for the application window.
`protected int `[`FrameCount`](#class_at_app_1_1_state_1aadd79c3c4bf69109501d103f59079746) | Frame counter used to measure framerate.
`protected int `[`Framerate`](#class_at_app_1_1_state_1a659b6af52165c885a020431dbc22907a) | Last known measurement of the application framerate.
`protected int `[`InputCount`](#class_at_app_1_1_state_1a7411f1c0d3a64cdccee373247df5e2c5) | Input counter used to measure 'inputs per second'.
`protected int `[`IPS`](#class_at_app_1_1_state_1a6c376e85a1fa7024d3f89d7d52cd092b) | Maximum allowed 'inputs per second'.
`protected int `[`MaximumRenderSkips`](#class_at_app_1_1_state_1a6b4370bded63894d3b651619a650ba6c) | Maximum allowed process loops between rendered frames.
`protected int `[`PPS`](#class_at_app_1_1_state_1a22ec959ac56b55f731920c38ca122c4e) | Target 'processes per second'.
`protected int `[`ProcessCount`](#class_at_app_1_1_state_1adf4af97fa4fe10cb86fc296862966cd5) | Process loop counter used to measure 'processes per second'.
`protected int `[`RenderSkips`](#class_at_app_1_1_state_1afe3d24f3a5b906b70dda27b167e72b3f) | Render skip counter used to measure process loops between rendered frames.
`protected int `[`WindowMode`](#class_at_app_1_1_state_1a3e70743d37f6528e3f9e97bd9019eea2) | Window mode set for the application window.
`protected lua_State * `[`Lua`](#class_at_app_1_1_state_1aaba2da0bad6d5625f8deaa39deef29fd) | Lua context for the Lua [API](#class_at_app_1_1_a_p_i).
`protected Vector2 `[`FullscreenResolution`](#class_at_app_1_1_state_1a9f629e3e24fad0a0d640ecd12f9f9f0b) | Set fullscreen resolution.
`protected Vector2 `[`PreviousFullscreenResolution`](#class_at_app_1_1_state_1a48e93d7f178fa4900e8cbdb1b82ea326) | Last known fullscreen resolution.
`protected Vector2 `[`WindowedResolution`](#class_at_app_1_1_state_1a335ac28ed636c7855ea9c1ea4ac6297a) | Set windowed resolution.
`protected SDL_GLContext `[`GLContext`](#class_at_app_1_1_state_1aba813451305d43c3afcd5f7c96976c19) | GLContext used for rendering.
`protected SDL_Window * `[`Window`](#class_at_app_1_1_state_1a97b33b6e3667c8b87445816798a7ce99) | Created SDL_Window instance.
`protected std::string `[`Icon`](#class_at_app_1_1_state_1a96f51e069a45590d1f6c4053264071fd) | Path to the application icon.
`protected std::string `[`Title`](#class_at_app_1_1_state_1a8377f54cce6338b3bfaf30f0d942204b) | Application title.
`protected std::vector< int > `[`EventQueue`](#class_at_app_1_1_state_1aff04cd1945be5c0d563484af123ba409) | Event stack to process input events.
`protected float `[`GetInputTimeStep`](#class_at_app_1_1_state_1a6bb925e12e056758c1bd0b41f86c1faa)`()` | Returns the minimum time interval at which input events are processed.
`protected float `[`GetProcessTimeStep`](#class_at_app_1_1_state_1a02f8f4f33b596656554e2c2d0cc129c8)`()` | Returns the minimum time interval between two game process loops.
`protected void `[`Update`](#class_at_app_1_1_state_1a5407b5637d39f37fc118d6cf6e406db7)`()` | Used internally to update the various counters of the application and the window title.

## AtApp::State Members

#### `public  `[`State`](#class_at_app_1_1_state_1a8b85ab3f0709f78d3031724a90fae542)`(lua_State * Lua,std::string Title,std::string Icon,int Width,int Height)` 

Basic constructor.

#### Parameters
* `Lua` Used to set the Lua context for the [API](#class_at_app_1_1_a_p_i) implementation. 

* `Title` `Icon` Used to initialise the title and icon of the application window. 

* `Width` `Height` Used to initialise the resolution of the application window.

#### `public  `[`~State`](#class_at_app_1_1_state_1aea9467d7e935d4783ee127555ae95b19)`()` 

Basic destructor.

#### `public int `[`GetAvailableVideoModes`](#class_at_app_1_1_state_1aa82868153cde0db0dda21c2a39bf8b01)`()` 

Returns the number of permitted display modes.

The returned number of display modes is referring to the current display, set by DisplayIndex.

#### `public int `[`GetDisplayIndex`](#class_at_app_1_1_state_1a4db320076857fdbf7e9ec425b2056c02)`()` 

Returns the index of the display the application is assigned to.

#### `public int `[`GetFramerate`](#class_at_app_1_1_state_1ac64f74ada37dcfff442f41d5dafae490)`()` 

Returns the framerate of the application.

The framerate is measured and updated once every second.

#### `public int `[`GetHeight`](#class_at_app_1_1_state_1af5baea0569c3b1d5383c99b676b0126b)`(int WindowMode)` 

Returns the height of the application window.

#### Parameters
* `WindowMode` If specified, the function will return the height for that window mode. If not specified, the height for the current window mode will be returned.

#### `public float `[`GetInterpolation`](#class_at_app_1_1_state_1a55c2a10a633bca3e5d177e27eb384926)`()` 

Returns a value which may be used to interpolate the position of objects during rendering.

#### `public int `[`GetIPS`](#class_at_app_1_1_state_1ae301bb573831d3f2995d59c1629df61e)`()` 

Returns the maximum allowed rate of input events.

#### `public int `[`GetPPS`](#class_at_app_1_1_state_1ab1167564a728d2f59f19c5599b43cb69)`()` 

Returns the process speed of the main game loop.

#### `public int `[`IsKeyPressed`](#class_at_app_1_1_state_1a9387910129e9dcac1f961f676e56b28d)`(SDL_Scancode Key)` 

Used to check if a specified key is pressed.

#### Parameters
* `Key` Uses the SDL_Scancode enumeration. Supports some custom definitions such as SDL_CUSTOM_SHIFT.

#### `public float `[`GetRuntime`](#class_at_app_1_1_state_1afc1b2159490b7d6c7c97c9ec8d664bd9)`()` 

Returns the current runtime of the application in seconds.

#### `public std::string `[`GetVideoMode`](#class_at_app_1_1_state_1a539d51d23e4d98f184e5441901ddd980)`(int i)` 

Returns the video mode at the specified index.

The returned string is in the following format: "(Width)x(Height)".

#### `public bool `[`GetVSync`](#class_at_app_1_1_state_1a31e00b950f2d863bd4b1041874da0914)`()` 

Returns the VSync property.

#### `public int `[`GetWidth`](#class_at_app_1_1_state_1a575a7c9650a9c9a0449a2ac0da30bda0)`(int WindowMode)` 

Returns the width of the application window.

#### Parameters
* `WindowMode` If specified, the function will return the width for that window mode. If not specified, the width for the current window mode will be returned.

#### `public int `[`GetWindowMode`](#class_at_app_1_1_state_1ac11f0e6199246cd0615bb11d35d7ec0a)`()` 

Returns the WindowMode property.

#### `public bool `[`IsRunning`](#class_at_app_1_1_state_1a8c05eb01b5d320ddab35300600d6a377)`()` 

Checks if the application is running.

#### `public std::string `[`SDLScancodeToText`](#class_at_app_1_1_state_1acc477600727d108db31d7d806f9da91a)`(SDL_Scancode Key,bool Short)` 

Converts a specified SDL_Scancode to text.

Used to display different keys in UI menus. 
#### Parameters
* `Key` The SDL_Scancode to convert to text. 

* `Short` When true, certain keys are made shorter, e.g. "Bkspc" is short for "Backspace".

#### `public void `[`AllowResize`](#class_at_app_1_1_state_1a02c5c5f070ab92a463989dc5064a0f8f)`(bool State)` 

Enables or disables resizing of the application window.

#### `public void `[`ApplyVideoMode`](#class_at_app_1_1_state_1a1b625b7ba2b34e5a0c3dd9494b2b22c6)`()` 

Applies current video mode settings.

#### `public bool `[`CanInput`](#class_at_app_1_1_state_1a74f542d5740fbcf5c94fbf3f183215e9)`()` 

Checks if input is allowed.

Used to regulate the speed of user input when a large number of input events are generated by the user.

#### `public bool `[`CanProcess`](#class_at_app_1_1_state_1af106eb246cc84a7ff472bdae5a661e9f)`()` 

Checks if the application is allowed to complete a process loop.

Used to regulate the speed of the main game loop.

#### `public void `[`Close`](#class_at_app_1_1_state_1afadc1544eddf5e7ffe5afcaa1c2b380a)`()` 

Closes the application window.

#### `public void `[`Hide`](#class_at_app_1_1_state_1af8c2c62e8a5a1194997d71db5572398e)`()` 

Hides the application window.

#### `public int `[`Input`](#class_at_app_1_1_state_1a3b0d6ad1c8fb3d9c3f41a1dc354bb79e)`(SDL_Event & Event)` 

Used to handle all SDL input events.

#### `public void `[`SaveScreenshot`](#class_at_app_1_1_state_1a6c7f845bc99b0eb80ceda303ff191109)`(std::string Location)` 

Saves a screenshot at the specified location.

The filename of the saved screenshot is in the following format: YYYYMMDDHHmmss

#### `public void `[`SetDisplayIndex`](#class_at_app_1_1_state_1a8b839c61a206eba7744e2367d6592278)`(int DisplayIndex)` 

Sets the display of the application window.

#### `public void `[`SetIcon`](#class_at_app_1_1_state_1afb020410cbb25598a420b00bbd21fbf4)`(std::string Icon)` 

Sets the icon of the application window.

#### `public void `[`SetIPS`](#class_at_app_1_1_state_1a751ac97dba347e47de76f0274d82a6db)`(int IPS)` 

Sets the maximum allowed inputs per second.

#### `public void `[`SetPosition`](#class_at_app_1_1_state_1a5eecef13b026316676045d9be5a2ab26)`(int X,int Y)` 

Positions the window at the specified coordinates.

#### `public void `[`SetPPS`](#class_at_app_1_1_state_1a3c9e9e3266fb0520b74518ecd68209ba)`(int PPS,int MaximumRenderSkips)` 

Sets the intended process speed for the application.

#### `public void `[`SetResolution`](#class_at_app_1_1_state_1a4f6c9b2eba0dee0c8ace97f820b2f607)`(int Width,int Height,int WindowMode)` 

Sets the width and height of the application.

#### Parameters
* `Width` `Height` The specified resolution. 

* `WindowMode` The window mode for which the resolution is intended. If not specified, the current window mode is used.

#### `public void `[`SetTitle`](#class_at_app_1_1_state_1afabfd3224811a0b04c7fcc41100d17e4)`(std::string Title)` 

Sets the title of the window application.

#### `public void `[`SetTitleStats`](#class_at_app_1_1_state_1ae3ea011f2ef6aad9fb055232f5cce72a)`(bool State)` 

Enables of disables various application information from being included on the window title.

#### `public void `[`SetVSync`](#class_at_app_1_1_state_1a1a9006d8525966b016df321fa227c6db)`(bool VSync)` 

Sets the VSync option.

#### `public void `[`SetWindowMode`](#class_at_app_1_1_state_1af8a0b611006c5d592d4d4154282e098e)`(int WindowMode)` 

Sets the window mode of the application.

#### `public void `[`Show`](#class_at_app_1_1_state_1a3e6676f18d78d4cebcdaa5326b9fa543)`()` 

Shows the application window.

#### `public void `[`ShowBorder`](#class_at_app_1_1_state_1aa9084adf92583e0f828d38668de6afa3)`(bool State)` 

Enables or disables the border of the application window.

#### `public bool `[`Start`](#class_at_app_1_1_state_1ab822dfe0ea819650cf9a78bd10d2e01f)`(Uint32 Flags,unsigned int D,int DisplayIndex)` 

Used to start the application.

#### Parameters
* `Flags` Set of flags used to initialise the application. 

* `D` 2 for 2D, 3 for 3D. 

* `DisplayIndex` Index of the display to use.

#### `public void `[`Stop`](#class_at_app_1_1_state_1afcc60ccf076ffbc27c8fff104fe63f8a)`()` 

Stops the application from running.

This function does not close the application window.

#### `protected bool `[`Bordered`](#class_at_app_1_1_state_1ab384e8cb2d5f48ac6863e88be38b746d) 

Determines if the application window will have a border.

#### `protected bool `[`Resizable`](#class_at_app_1_1_state_1ac1efcff1acbba2458641b23a189329a0) 

Determines if the application window is resizable.

#### `protected bool `[`Status`](#class_at_app_1_1_state_1ac53a340bd15a7195bdb02eb2b84e56ba) 

Set to true if the application is running.

#### `protected bool `[`TitleStats`](#class_at_app_1_1_state_1a85d93a63a0f563a6988410149bd6745a) 

Determines if information about the application is shown as the window title.

#### `protected bool `[`VSync`](#class_at_app_1_1_state_1aec3d44d2fd71f017d401de7b8fd22c8b) 

Determines the VSync property of the application.

#### `protected float `[`LastUpdate`](#class_at_app_1_1_state_1a7743aaae4242bc3bab4eada530387f00) 

Timestamp of the last known application update.

#### `protected float `[`NextInput`](#class_at_app_1_1_state_1a979036af7e77c79a19e7ff2fca5a35a8) 

Timestamp for the next earliest accepted input to the application.

#### `protected float `[`NextProcess`](#class_at_app_1_1_state_1ae946585e5af8acdb65fd8661b716118b) 

Timestamp for the next intended application process loop.

#### `protected int `[`CurrentIPS`](#class_at_app_1_1_state_1a6a6c5b7f9248e2394160e2063eb07e68) 

Last known measurement of 'inputs per second'.

#### `protected int `[`CurrentPPS`](#class_at_app_1_1_state_1abdba7437312bd5b66b8ed41ea0321d2d) 

Last known measurement of 'processes per second'.

#### `protected int `[`DisplayIndex`](#class_at_app_1_1_state_1ac47717b9901f80725733dc4c7ea08b8d) 

Index of the display used for the application window.

#### `protected int `[`FrameCount`](#class_at_app_1_1_state_1aadd79c3c4bf69109501d103f59079746) 

Frame counter used to measure framerate.

#### `protected int `[`Framerate`](#class_at_app_1_1_state_1a659b6af52165c885a020431dbc22907a) 

Last known measurement of the application framerate.

#### `protected int `[`InputCount`](#class_at_app_1_1_state_1a7411f1c0d3a64cdccee373247df5e2c5) 

Input counter used to measure 'inputs per second'.

#### `protected int `[`IPS`](#class_at_app_1_1_state_1a6c376e85a1fa7024d3f89d7d52cd092b) 

Maximum allowed 'inputs per second'.

#### `protected int `[`MaximumRenderSkips`](#class_at_app_1_1_state_1a6b4370bded63894d3b651619a650ba6c) 

Maximum allowed process loops between rendered frames.

#### `protected int `[`PPS`](#class_at_app_1_1_state_1a22ec959ac56b55f731920c38ca122c4e) 

Target 'processes per second'.

#### `protected int `[`ProcessCount`](#class_at_app_1_1_state_1adf4af97fa4fe10cb86fc296862966cd5) 

Process loop counter used to measure 'processes per second'.

#### `protected int `[`RenderSkips`](#class_at_app_1_1_state_1afe3d24f3a5b906b70dda27b167e72b3f) 

Render skip counter used to measure process loops between rendered frames.

#### `protected int `[`WindowMode`](#class_at_app_1_1_state_1a3e70743d37f6528e3f9e97bd9019eea2) 

Window mode set for the application window.

#### `protected lua_State * `[`Lua`](#class_at_app_1_1_state_1aaba2da0bad6d5625f8deaa39deef29fd) 

Lua context for the Lua [API](#class_at_app_1_1_a_p_i).

#### `protected Vector2 `[`FullscreenResolution`](#class_at_app_1_1_state_1a9f629e3e24fad0a0d640ecd12f9f9f0b) 

Set fullscreen resolution.

#### `protected Vector2 `[`PreviousFullscreenResolution`](#class_at_app_1_1_state_1a48e93d7f178fa4900e8cbdb1b82ea326) 

Last known fullscreen resolution.

#### `protected Vector2 `[`WindowedResolution`](#class_at_app_1_1_state_1a335ac28ed636c7855ea9c1ea4ac6297a) 

Set windowed resolution.

#### `protected SDL_GLContext `[`GLContext`](#class_at_app_1_1_state_1aba813451305d43c3afcd5f7c96976c19) 

GLContext used for rendering.

#### `protected SDL_Window * `[`Window`](#class_at_app_1_1_state_1a97b33b6e3667c8b87445816798a7ce99) 

Created SDL_Window instance.

#### `protected std::string `[`Icon`](#class_at_app_1_1_state_1a96f51e069a45590d1f6c4053264071fd) 

Path to the application icon.

#### `protected std::string `[`Title`](#class_at_app_1_1_state_1a8377f54cce6338b3bfaf30f0d942204b) 

Application title.

#### `protected std::vector< int > `[`EventQueue`](#class_at_app_1_1_state_1aff04cd1945be5c0d563484af123ba409) 

Event stack to process input events.

#### `protected float `[`GetInputTimeStep`](#class_at_app_1_1_state_1a6bb925e12e056758c1bd0b41f86c1faa)`()` 

Returns the minimum time interval at which input events are processed.

#### `protected float `[`GetProcessTimeStep`](#class_at_app_1_1_state_1a02f8f4f33b596656554e2c2d0cc129c8)`()` 

Returns the minimum time interval between two game process loops.

#### `protected void `[`Update`](#class_at_app_1_1_state_1a5407b5637d39f37fc118d6cf6e406db7)`()` 

Used internally to update the various counters of the application and the window title.

Generated by [Moxygen](https://sourcey.com/moxygen)