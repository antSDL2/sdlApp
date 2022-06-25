//API.h
#ifndef NEOAPP_API_H
#define NEOAPP_API_H

#include <iostream>
#include "State.h"

#include <sdlUtility/Lua.h>
#include <sdlUtility/Strings.h>

using namespace sdlUtility;

namespace sdlApp {
	/// Used to define, implement, and load a Lua API for the sdlApp::State class.
	/** In addition to API handles for the sdlApp::State class, this class implements various globals, such as the entire SDL_Scancode enum, global events, and related functions.
        The object 'Application' is used to call methods of sdlApp::State in Lua scripts, e.g. Application:GetFramerate(); */
    class API {
        //Members
        protected:
            static State *Application;                          //!< Pointer to the sdlApp::State instance used in the API.
        //Access Methods
        protected:
       API();
            ~API();
        //Process Methods
        public:
            /// Used to load the Lua API to the specified Lua context.
            static void Load(lua_State *Lua, State *State) {
                Application = State;

                if (Application == NULL) std::cerr << "(Application/API.h) Load(): Application pointer was not defined (NULL)." << std::endl;
                if (Lua == NULL) {
                    std::cerr << "(Application/API.h) Load(): Lua pointer was not defined (NULL)." << std::endl;
                } else {
                    lua_pushinteger(Lua, 1);
                    lua_setglobal(Lua, "AT_X");
                    lua_pushinteger(Lua, 2);
                    lua_setglobal(Lua, "AT_Y");
                    lua_pushinteger(Lua, 3);
                    lua_setglobal(Lua, "AT_XY");

                    lua_pushinteger(Lua, 0);
                    lua_setglobal(Lua, "SDL_SCANCODE_UNKNOWN");
                    lua_pushinteger(Lua, 4);
                    lua_setglobal(Lua, "SDL_SCANCODE_A");
                    lua_pushinteger(Lua, 5);
                    lua_setglobal(Lua, "SDL_SCANCODE_B");
                    lua_pushinteger(Lua, 6);
                    lua_setglobal(Lua, "SDL_SCANCODE_C");
                    lua_pushinteger(Lua, 7);
                    lua_setglobal(Lua, "SDL_SCANCODE_D");
                    lua_pushinteger(Lua, 8);
                    lua_setglobal(Lua, "SDL_SCANCODE_E");
                    lua_pushinteger(Lua, 9);
                    lua_setglobal(Lua, "SDL_SCANCODE_F");
                    lua_pushinteger(Lua, 10);
                    lua_setglobal(Lua, "SDL_SCANCODE_G");
                    lua_pushinteger(Lua, 11);
                    lua_setglobal(Lua, "SDL_SCANCODE_H");
                    lua_pushinteger(Lua, 12);
                    lua_setglobal(Lua, "SDL_SCANCODE_I");
                    lua_pushinteger(Lua, 13);
                    lua_setglobal(Lua, "SDL_SCANCODE_J");
                    lua_pushinteger(Lua, 14);
                    lua_setglobal(Lua, "SDL_SCANCODE_K");
                    lua_pushinteger(Lua, 15);
                    lua_setglobal(Lua, "SDL_SCANCODE_L");
                    lua_pushinteger(Lua, 16);
                    lua_setglobal(Lua, "SDL_SCANCODE_M");
                    lua_pushinteger(Lua, 17);
                    lua_setglobal(Lua, "SDL_SCANCODE_N");
                    lua_pushinteger(Lua, 18);
                    lua_setglobal(Lua, "SDL_SCANCODE_O");
                    lua_pushinteger(Lua, 19);
                    lua_setglobal(Lua, "SDL_SCANCODE_P");
                    lua_pushinteger(Lua, 20);
                    lua_setglobal(Lua, "SDL_SCANCODE_Q");
                    lua_pushinteger(Lua, 21);
                    lua_setglobal(Lua, "SDL_SCANCODE_R");
                    lua_pushinteger(Lua, 22);
                    lua_setglobal(Lua, "SDL_SCANCODE_S");
                    lua_pushinteger(Lua, 23);
                    lua_setglobal(Lua, "SDL_SCANCODE_T");
                    lua_pushinteger(Lua, 24);
                    lua_setglobal(Lua, "SDL_SCANCODE_U");
                    lua_pushinteger(Lua, 25);
                    lua_setglobal(Lua, "SDL_SCANCODE_V");
                    lua_pushinteger(Lua, 26);
                    lua_setglobal(Lua, "SDL_SCANCODE_W");
                    lua_pushinteger(Lua, 27);
                    lua_setglobal(Lua, "SDL_SCANCODE_X");
                    lua_pushinteger(Lua, 28);
                    lua_setglobal(Lua, "SDL_SCANCODE_Y");
                    lua_pushinteger(Lua, 29);
                    lua_setglobal(Lua, "SDL_SCANCODE_Z");

                    lua_pushinteger(Lua, 30);
                    lua_setglobal(Lua, "SDL_SCANCODE_1");
                    lua_pushinteger(Lua, 31);
                    lua_setglobal(Lua, "SDL_SCANCODE_2");
                    lua_pushinteger(Lua, 32);
                    lua_setglobal(Lua, "SDL_SCANCODE_3");
                    lua_pushinteger(Lua, 33);
                    lua_setglobal(Lua, "SDL_SCANCODE_4");
                    lua_pushinteger(Lua, 34);
                    lua_setglobal(Lua, "SDL_SCANCODE_5");
                    lua_pushinteger(Lua, 35);
                    lua_setglobal(Lua, "SDL_SCANCODE_6");
                    lua_pushinteger(Lua, 36);
                    lua_setglobal(Lua, "SDL_SCANCODE_7");
                    lua_pushinteger(Lua, 37);
                    lua_setglobal(Lua, "SDL_SCANCODE_8");
                    lua_pushinteger(Lua, 38);
                    lua_setglobal(Lua, "SDL_SCANCODE_9");
                    lua_pushinteger(Lua, 39);
                    lua_setglobal(Lua, "SDL_SCANCODE_0");

                    lua_pushinteger(Lua, 40);
                    lua_setglobal(Lua, "SDL_SCANCODE_RETURN");
                    lua_pushinteger(Lua, 41);
                    lua_setglobal(Lua, "SDL_SCANCODE_ESCAPE");
                    lua_pushinteger(Lua, 42);
                    lua_setglobal(Lua, "SDL_SCANCODE_BACKSPACE");
                    lua_pushinteger(Lua, 43);
                    lua_setglobal(Lua, "SDL_SCANCODE_TAB");
                    lua_pushinteger(Lua, 44);
                    lua_setglobal(Lua, "SDL_SCANCODE_SPACE");

                    lua_pushinteger(Lua, 45);
                    lua_setglobal(Lua, "SDL_SCANCODE_MINUS");
                    lua_pushinteger(Lua, 46);
                    lua_setglobal(Lua, "SDL_SCANCODE_EQUALS");
                    lua_pushinteger(Lua, 47);
                    lua_setglobal(Lua, "SDL_SCANCODE_LEFTBRACKET");
                    lua_pushinteger(Lua, 48);
                    lua_setglobal(Lua, "SDL_SCANCODE_RIGHTBRACKET");
                    lua_pushinteger(Lua, 49);
                    lua_setglobal(Lua, "SDL_SCANCODE_BACKSLASH");
                    lua_pushinteger(Lua, 50);
                    lua_setglobal(Lua, "SDL_SCANCODE_NONUSHASH");

                    lua_pushinteger(Lua, 51);
                    lua_setglobal(Lua, "SDL_SCANCODE_SEMICOLON");
                    lua_pushinteger(Lua, 52);
                    lua_setglobal(Lua, "SDL_SCANCODE_APOSTROPHE");
                    lua_pushinteger(Lua, 53);
                    lua_setglobal(Lua, "SDL_SCANCODE_GRAVE");
                    lua_pushinteger(Lua, 54);
                    lua_setglobal(Lua, "SDL_SCANCODE_COMMA");
                    lua_pushinteger(Lua, 55);
                    lua_setglobal(Lua, "SDL_SCANCODE_PERIOD");
                    lua_pushinteger(Lua, 56);
                    lua_setglobal(Lua, "SDL_SCANCODE_SLASH");

                    lua_pushinteger(Lua, 57);
                    lua_setglobal(Lua, "SDL_SCANCODE_CAPSLOCK");

                    lua_pushinteger(Lua, 58);
                    lua_setglobal(Lua, "SDL_SCANCODE_F1");
                    lua_pushinteger(Lua, 59);
                    lua_setglobal(Lua, "SDL_SCANCODE_F2");
                    lua_pushinteger(Lua, 60);
                    lua_setglobal(Lua, "SDL_SCANCODE_F3");
                    lua_pushinteger(Lua, 61);
                    lua_setglobal(Lua, "SDL_SCANCODE_F4");
                    lua_pushinteger(Lua, 62);
                    lua_setglobal(Lua, "SDL_SCANCODE_F5");
                    lua_pushinteger(Lua, 63);
                    lua_setglobal(Lua, "SDL_SCANCODE_F6");
                    lua_pushinteger(Lua, 64);
                    lua_setglobal(Lua, "SDL_SCANCODE_F7");
                    lua_pushinteger(Lua, 65);
                    lua_setglobal(Lua, "SDL_SCANCODE_F8");
                    lua_pushinteger(Lua, 66);
                    lua_setglobal(Lua, "SDL_SCANCODE_F9");
                    lua_pushinteger(Lua, 67);
                    lua_setglobal(Lua, "SDL_SCANCODE_F10");
                    lua_pushinteger(Lua, 68);
                    lua_setglobal(Lua, "SDL_SCANCODE_F11");
                    lua_pushinteger(Lua, 69);
                    lua_setglobal(Lua, "SDL_SCANCODE_F12");

                    lua_pushinteger(Lua, 70);
                    lua_setglobal(Lua, "SDL_SCANCODE_PRINTSCREEN");
                    lua_pushinteger(Lua, 71);
                    lua_setglobal(Lua, "SDL_SCANCODE_SCROLLLOCK");
                    lua_pushinteger(Lua, 72);
                    lua_setglobal(Lua, "SDL_SCANCODE_PAUSE");
                    lua_pushinteger(Lua, 73);
                    lua_setglobal(Lua, "SDL_SCANCODE_INSERT");
                    lua_pushinteger(Lua, 74);
                    lua_setglobal(Lua, "SDL_SCANCODE_HOME");
                    lua_pushinteger(Lua, 75);
                    lua_setglobal(Lua, "SDL_SCANCODE_PAGEUP");
                    lua_pushinteger(Lua, 76);
                    lua_setglobal(Lua, "SDL_SCANCODE_DELETE");
                    lua_pushinteger(Lua, 77);
                    lua_setglobal(Lua, "SDL_SCANCODE_END");
                    lua_pushinteger(Lua, 78);
                    lua_setglobal(Lua, "SDL_SCANCODE_PAGEDOWN");
                    lua_pushinteger(Lua, 79);
                    lua_setglobal(Lua, "SDL_SCANCODE_RIGHT");
                    lua_pushinteger(Lua, 80);
                    lua_setglobal(Lua, "SDL_SCANCODE_LEFT");
                    lua_pushinteger(Lua, 81);
                    lua_setglobal(Lua, "SDL_SCANCODE_DOWN");
                    lua_pushinteger(Lua, 82);
                    lua_setglobal(Lua, "SDL_SCANCODE_UP");

                    lua_pushinteger(Lua, 83);
                    lua_setglobal(Lua, "SDL_SCANCODE_NUMLOCKCLEAR");

                    lua_pushinteger(Lua, 84);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_DIVIDE");
                    lua_pushinteger(Lua, 85);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MULTIPLY");
                    lua_pushinteger(Lua, 86);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MINUS");
                    lua_pushinteger(Lua, 87);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_PLUS");
                    lua_pushinteger(Lua, 88);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_ENTER");
                    lua_pushinteger(Lua, 89);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_1");
                    lua_pushinteger(Lua, 90);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_2");
                    lua_pushinteger(Lua, 91);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_3");
                    lua_pushinteger(Lua, 92);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_4");
                    lua_pushinteger(Lua, 93);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_5");
                    lua_pushinteger(Lua, 94);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_6");
                    lua_pushinteger(Lua, 95);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_7");
                    lua_pushinteger(Lua, 96);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_8");
                    lua_pushinteger(Lua, 97);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_9");
                    lua_pushinteger(Lua, 98);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_0");
                    lua_pushinteger(Lua, 99);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_PERIOD");

                    lua_pushinteger(Lua, 100);
                    lua_setglobal(Lua, "SDL_SCANCODE_NONUSBACKSLASH");
                    lua_pushinteger(Lua, 101);
                    lua_setglobal(Lua, "SDL_SCANCODE_APPLICATION");
                    lua_pushinteger(Lua, 102);
                    lua_setglobal(Lua, "SDL_SCANCODE_POWER");
                    lua_pushinteger(Lua, 103);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_EQUALS");
                    lua_pushinteger(Lua, 104);
                    lua_setglobal(Lua, "SDL_SCANCODE_F13");
                    lua_pushinteger(Lua, 105);
                    lua_setglobal(Lua, "SDL_SCANCODE_F14");
                    lua_pushinteger(Lua, 106);
                    lua_setglobal(Lua, "SDL_SCANCODE_F15");
                    lua_pushinteger(Lua, 107);
                    lua_setglobal(Lua, "SDL_SCANCODE_F16");
                    lua_pushinteger(Lua, 108);
                    lua_setglobal(Lua, "SDL_SCANCODE_F17");
                    lua_pushinteger(Lua, 109);
                    lua_setglobal(Lua, "SDL_SCANCODE_F18");
                    lua_pushinteger(Lua, 110);
                    lua_setglobal(Lua, "SDL_SCANCODE_F19");
                    lua_pushinteger(Lua, 111);
                    lua_setglobal(Lua, "SDL_SCANCODE_F20");
                    lua_pushinteger(Lua, 112);
                    lua_setglobal(Lua, "SDL_SCANCODE_F21");
                    lua_pushinteger(Lua, 113);
                    lua_setglobal(Lua, "SDL_SCANCODE_F22");
                    lua_pushinteger(Lua, 114);
                    lua_setglobal(Lua, "SDL_SCANCODE_F23");
                    lua_pushinteger(Lua, 115);
                    lua_setglobal(Lua, "SDL_SCANCODE_F24");
                    lua_pushinteger(Lua, 116);
                    lua_setglobal(Lua, "SDL_SCANCODE_EXECUTE");
                    lua_pushinteger(Lua, 117);
                    lua_setglobal(Lua, "SDL_SCANCODE_HELP");
                    lua_pushinteger(Lua, 118);
                    lua_setglobal(Lua, "SDL_SCANCODE_MENU");
                    lua_pushinteger(Lua, 119);
                    lua_setglobal(Lua, "SDL_SCANCODE_SELECT");
                    lua_pushinteger(Lua, 120);
                    lua_setglobal(Lua, "SDL_SCANCODE_STOP");
                    lua_pushinteger(Lua, 121);
                    lua_setglobal(Lua, "SDL_SCANCODE_AGAIN"); /* redo */
                    lua_pushinteger(Lua, 122);
                    lua_setglobal(Lua, "SDL_SCANCODE_UNDO");
                    lua_pushinteger(Lua, 123);
                    lua_setglobal(Lua, "SDL_SCANCODE_CUT");
                    lua_pushinteger(Lua, 124);
                    lua_setglobal(Lua, "SDL_SCANCODE_COPY");
                    lua_pushinteger(Lua, 125);
                    lua_setglobal(Lua, "SDL_SCANCODE_PASTE");
                    lua_pushinteger(Lua, 126);
                    lua_setglobal(Lua, "SDL_SCANCODE_FIND");
                    lua_pushinteger(Lua, 127);
                    lua_setglobal(Lua, "SDL_SCANCODE_MUTE");
                    lua_pushinteger(Lua, 128);
                    lua_setglobal(Lua, "SDL_SCANCODE_VOLUMEUP");
                    lua_pushinteger(Lua, 129);
                    lua_setglobal(Lua, "SDL_SCANCODE_VOLUMEDOWN");
                    /* not sure whether there's a reason to enable these */
                    /*     SDL_SCANCODE_LOCKINGCAPSLOCK = 130,  */
                    /*     SDL_SCANCODE_LOCKINGNUMLOCK = 131, */
                    /*     SDL_SCANCODE_LOCKINGSCROLLLOCK = 132, */
                    lua_pushinteger(Lua, 133);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_COMMA");
                    lua_pushinteger(Lua, 134);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_EQUALSAS400");
                    lua_pushinteger(Lua, 135);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL1");
                    lua_pushinteger(Lua, 136);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL2");
                    lua_pushinteger(Lua, 137);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL3");
                    lua_pushinteger(Lua, 138);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL4");
                    lua_pushinteger(Lua, 139);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL5");
                    lua_pushinteger(Lua, 140);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL6");
                    lua_pushinteger(Lua, 141);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL7");
                    lua_pushinteger(Lua, 142);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL8");
                    lua_pushinteger(Lua, 143);
                    lua_setglobal(Lua, "SDL_SCANCODE_INTERNATIONAL9");
                    lua_pushinteger(Lua, 144);
                    lua_setglobal(Lua, "SDL_SCANCODE_LANG1");
                    lua_pushinteger(Lua, 145);
                    lua_setglobal(Lua, "SDL_SCANCODE_LANG2");
                    lua_pushinteger(Lua, 146);
                    lua_setglobal(Lua, "SDL_SCANCODE_LANG3");
                    lua_pushinteger(Lua, 147);
                    lua_setglobal(Lua, "SDL_SCANCODE_LANG4");
                    lua_pushinteger(Lua, 148);
                    lua_setglobal(Lua, "SDL_SCANCODE_LANG5");
                    /*
                    SDL_SCANCODE_LANG6 = 149, // reserved
                    SDL_SCANCODE_LANG7 = 150, // reserved
                    SDL_SCANCODE_LANG8 = 151, // reserved
                    SDL_SCANCODE_LANG9 = 152, // reserved
                    */
                    lua_pushinteger(Lua, 153);
                    lua_setglobal(Lua, "SDL_SCANCODE_ALTERASE");
                    lua_pushinteger(Lua, 154);
                    lua_setglobal(Lua, "SDL_SCANCODE_SYSREQ");
                    lua_pushinteger(Lua, 155);
                    lua_setglobal(Lua, "SDL_SCANCODE_CANCEL");
                    lua_pushinteger(Lua, 156);
                    lua_setglobal(Lua, "SDL_SCANCODE_CLEAR");
                    lua_pushinteger(Lua, 157);
                    lua_setglobal(Lua, "SDL_SCANCODE_PRIOR");
                    lua_pushinteger(Lua, 158);
                    lua_setglobal(Lua, "SDL_SCANCODE_RETURN2");
                    lua_pushinteger(Lua, 159);
                    lua_setglobal(Lua, "SDL_SCANCODE_SEPARATOR");
                    lua_pushinteger(Lua, 160);
                    lua_setglobal(Lua, "SDL_SCANCODE_OUT");
                    lua_pushinteger(Lua, 161);
                    lua_setglobal(Lua, "SDL_SCANCODE_OPER");
                    lua_pushinteger(Lua, 162);
                    lua_setglobal(Lua, "SDL_SCANCODE_CLEARAGAIN");
                    lua_pushinteger(Lua, 163);
                    lua_setglobal(Lua, "SDL_SCANCODE_CRSEL");
                    lua_pushinteger(Lua, 164);
                    lua_setglobal(Lua, "SDL_SCANCODE_EXSEL");

                    lua_pushinteger(Lua, 176);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_00");
                    lua_pushinteger(Lua, 177);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_000");
                    lua_pushinteger(Lua, 178);
                    lua_setglobal(Lua, "SDL_SCANCODE_THOUSANDSSEPARATOR");
                    lua_pushinteger(Lua, 179);
                    lua_setglobal(Lua, "SDL_SCANCODE_DECIMALSEPARATOR");
                    lua_pushinteger(Lua, 180);
                    lua_setglobal(Lua, "SDL_SCANCODE_CURRENCYUNIT");
                    lua_pushinteger(Lua, 181);
                    lua_setglobal(Lua, "SDL_SCANCODE_CURRENCYSUBUNIT");
                    lua_pushinteger(Lua, 182);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_LEFTPAREN");
                    lua_pushinteger(Lua, 183);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_RIGHTPAREN");
                    lua_pushinteger(Lua, 184);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_LEFTBRACE");
                    lua_pushinteger(Lua, 185);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_RIGHTBRACE");
                    lua_pushinteger(Lua, 186);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_TAB");
                    lua_pushinteger(Lua, 187);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_BACKSPACE");
                    lua_pushinteger(Lua, 188);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_A");
                    lua_pushinteger(Lua, 189);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_B");
                    lua_pushinteger(Lua, 190);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_C");
                    lua_pushinteger(Lua, 191);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_D");
                    lua_pushinteger(Lua, 192);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_E");
                    lua_pushinteger(Lua, 193);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_F");
                    lua_pushinteger(Lua, 194);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_XOR");
                    lua_pushinteger(Lua, 195);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_POWER");
                    lua_pushinteger(Lua, 196);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_PERCENT");
                    lua_pushinteger(Lua, 197);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_LESS");
                    lua_pushinteger(Lua, 198);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_GREATER");
                    lua_pushinteger(Lua, 199);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_AMPERSAND");
                    lua_pushinteger(Lua, 200);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_DBLAMPERSAND");
                    lua_pushinteger(Lua, 201);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_VERTICALBAR");
                    lua_pushinteger(Lua, 202);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_DBLVERTICALBAR");
                    lua_pushinteger(Lua, 203);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_COLON");
                    lua_pushinteger(Lua, 204);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_HASH");
                    lua_pushinteger(Lua, 205);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_SPACE");
                    lua_pushinteger(Lua, 206);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_AT");
                    lua_pushinteger(Lua, 207);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_EXCLAM");
                    lua_pushinteger(Lua, 208);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMSTORE");
                    lua_pushinteger(Lua, 209);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMRECALL");
                    lua_pushinteger(Lua, 210);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMCLEAR");
                    lua_pushinteger(Lua, 211);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMADD");
                    lua_pushinteger(Lua, 212);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMSUBTRACT");
                    lua_pushinteger(Lua, 213);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMMULTIPLY");
                    lua_pushinteger(Lua, 214);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_MEMDIVIDE");
                    lua_pushinteger(Lua, 215);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_PLUSMINUS");
                    lua_pushinteger(Lua, 216);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_CLEAR");
                    lua_pushinteger(Lua, 217);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_CLEARENTRY");
                    lua_pushinteger(Lua, 218);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_BINARY");
                    lua_pushinteger(Lua, 219);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_OCTAL");
                    lua_pushinteger(Lua, 220);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_DECIMAL");
                    lua_pushinteger(Lua, 221);
                    lua_setglobal(Lua, "SDL_SCANCODE_KP_HEXADECIMAL");

                    lua_pushinteger(Lua, 224);
                    lua_setglobal(Lua, "SDL_SCANCODE_LCTRL");
                    lua_pushinteger(Lua, 225);
                    lua_setglobal(Lua, "SDL_SCANCODE_LSHIFT");
                    lua_pushinteger(Lua, 226);
                    lua_setglobal(Lua, "SDL_SCANCODE_LALT");
                    lua_pushinteger(Lua, 227);
                    lua_setglobal(Lua, "SDL_SCANCODE_LGUI");
                    lua_pushinteger(Lua, 228);
                    lua_setglobal(Lua, "SDL_SCANCODE_RCTRL");
                    lua_pushinteger(Lua, 229);
                    lua_setglobal(Lua, "SDL_SCANCODE_RSHIFT");
                    lua_pushinteger(Lua, 230);
                    lua_setglobal(Lua, "SDL_SCANCODE_RALT");
                    lua_pushinteger(Lua, 231);
                    lua_setglobal(Lua, "SDL_SCANCODE_RGUI");

                    lua_pushinteger(Lua, 257);
                    lua_setglobal(Lua, "SDL_SCANCODE_MODE");

                    lua_pushinteger(Lua, 258);
                    lua_setglobal(Lua, "SDL_SCANCODE_AUDIONEXT");
                    lua_pushinteger(Lua, 259);
                    lua_setglobal(Lua, "SDL_SCANCODE_AUDIOPREV");
                    lua_pushinteger(Lua, 260);
                    lua_setglobal(Lua, "SDL_SCANCODE_AUDIOSTOP");
                    lua_pushinteger(Lua, 261);
                    lua_setglobal(Lua, "SDL_SCANCODE_AUDIOPLAY");
                    lua_pushinteger(Lua, 262);
                    lua_setglobal(Lua, "SDL_SCANCODE_AUDIOMUTE");
                    lua_pushinteger(Lua, 263);
                    lua_setglobal(Lua, "SDL_SCANCODE_MEDIASELECT");
                    lua_pushinteger(Lua, 264);
                    lua_setglobal(Lua, "SDL_SCANCODE_WWW");
                    lua_pushinteger(Lua, 265);
                    lua_setglobal(Lua, "SDL_SCANCODE_MAIL");
                    lua_pushinteger(Lua, 266);
                    lua_setglobal(Lua, "SDL_SCANCODE_CALCULATOR");
                    lua_pushinteger(Lua, 267);
                    lua_setglobal(Lua, "SDL_SCANCODE_COMPUTER");
                    lua_pushinteger(Lua, 268);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_SEARCH");
                    lua_pushinteger(Lua, 269);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_HOME");
                    lua_pushinteger(Lua, 270);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_BACK");
                    lua_pushinteger(Lua, 271);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_FORWARD");
                    lua_pushinteger(Lua, 272);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_STOP");
                    lua_pushinteger(Lua, 273);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_REFRESH");
                    lua_pushinteger(Lua, 274);
                    lua_setglobal(Lua, "SDL_SCANCODE_AC_BOOKMARKS");

                    lua_pushinteger(Lua, 275);
                    lua_setglobal(Lua, "SDL_SCANCODE_BRIGHTNESSDOWN");
                    lua_pushinteger(Lua, 276);
                    lua_setglobal(Lua, "SDL_SCANCODE_BRIGHTNESSUP");
                    lua_pushinteger(Lua, 277);
                    lua_setglobal(Lua, "SDL_SCANCODE_DISPLAYSWITCH");
                    lua_pushinteger(Lua, 278);
                    lua_setglobal(Lua, "SDL_SCANCODE_KBDILLUMTOGGLE");
                    lua_pushinteger(Lua, 279);
                    lua_setglobal(Lua, "SDL_SCANCODE_KBDILLUMDOWN");
                    lua_pushinteger(Lua, 280);
                    lua_setglobal(Lua, "SDL_SCANCODE_KBDILLUMUP");
                    lua_pushinteger(Lua, 281);
                    lua_setglobal(Lua, "SDL_SCANCODE_EJECT");
                    lua_pushinteger(Lua, 282);
                    lua_setglobal(Lua, "SDL_SCANCODE_SLEEP");

                    lua_pushinteger(Lua, 283);
                    lua_setglobal(Lua, "SDL_SCANCODE_APP1");
                    lua_pushinteger(Lua, 284);
                    lua_setglobal(Lua, "SDL_SCANCODE_APP2");

                    lua_pushinteger(Lua, 1001);
                    lua_setglobal(Lua, "SDL_CUSTOM_CTRL");
                    lua_pushinteger(Lua, 1002);
                    lua_setglobal(Lua, "SDL_CUSTOM_SHIFT");
                    lua_pushinteger(Lua, 1003);
                    lua_setglobal(Lua, "SDL_CUSTOM_ALT");
                    lua_pushinteger(Lua, 1004);
                    lua_setglobal(Lua, "SDL_CUSTOM_LMB");
                    lua_pushinteger(Lua, 1005);
                    lua_setglobal(Lua, "SDL_CUSTOM_RMB");
                    lua_pushinteger(Lua, 1006);
                    lua_setglobal(Lua, "SDL_CUSTOM_MMB");
                    lua_pushinteger(Lua, 1007);
                    lua_setglobal(Lua, "SDL_CUSTOM_X1MB");
                    lua_pushinteger(Lua, 1008);
                    lua_setglobal(Lua, "SDL_CUSTOM_X2MB");

                    static const luaL_Reg Application[] = {
                        {"GetAvailableVideoModes", API::GetAvailableVideoModes},
                        {"GetFramerate", API::GetFramerate},
                        {"GetHeight", API::GetHeight},
                        {"GetIPS", API::GetIPS},
                        {"GetPPS", API::GetPPS},
                        {"GetRuntime", API::GetRuntime},
                        {"GetVSync", API::GetVSync},
                        {"GetVideoMode", API::GetVideoMode},
                        {"GetWidth", API::GetWidth},
                        {"GetWindowMode", API::GetWindowMode},
                        {"IsKeyPressed", API::IsKeyPressed},
                        {"SDLScancodeToText", API::SDLScancodeToText},

                        {"AllowResize", API::AllowResize},
                        {"ApplyVideoMode", API::ApplyVideoMode},
                        {"SaveScreenshot", API::SaveScreenshot},
                        {"SetIPS", API::SetIPS},
                        {"SetPPS", API::SetPPS},
                        {"SetResolution", API::SetResolution},
                        {"SetTitle", API::SetTitle},
                        {"SetVSync", API::SetVSync},
                        {"SetWindowMode", API::SetWindowMode},
                        {"ShowBorder", API::ShowBorder},
                        {"Stop", API::Stop},
                        {NULL, NULL}
                    };

                    luaL_newlib(Lua, Application);
                    lua_setglobal(Lua, "Application");

                    //WindowModes namespace
                    lua_pushinteger(Lua, 0);
                    lua_setglobal(Lua, "WM_WINDOWED");

                    lua_pushinteger(Lua, 1);
                    lua_setglobal(Lua, "WM_FULLSCREEN");

                    lua_pushinteger(Lua, 2);
                    lua_setglobal(Lua, "WM_BORDERLESS");

                    lua_pushinteger(Lua, 3);
                    lua_setglobal(Lua, "WM_MAXIMISED");

                    //GlobalEvents
                    lua_getglobal(Lua, "GlobalEvents");

                    if (lua_isnil(Lua, -1)) {
                        lua_newtable(Lua);
                    }

                    lua_newtable(Lua);
                    lua_setfield(Lua, -2, "KeyDown");
                    lua_newtable(Lua);
                    lua_setfield(Lua, -2, "KeyUp");
                    lua_newtable(Lua);
                    lua_setfield(Lua, -2, "ResolutionChanged");

                    Lua::ExecuteScript(Lua, "function Application.OnGlobalEvent(Event, ...) for CallerName,CallbackValues in pairs(GlobalEvents[Event]) do local Caller = CallbackValues[0]; Caller.Callback = CallbackValues[1]; Caller.Callback(...); end end");
                    Lua::ExecuteScript(Lua, "function Application.RegisterEventHandler(Event, Caller, Value) if (Caller and Value and Event) then GlobalEvents[Event][Caller.ID] = {[0] = Caller, [1] = Value}; end end");
                    Lua::ExecuteScript(Lua, "function Application.RemoveEventHandlers(CallerID) for Event in pairs(GlobalEvents) do if (GlobalEvents[Event]) then GlobalEvents[Event][CallerID] = nil; end end end");

                    lua_setglobal(Lua, "GlobalEvents");
                }
            }

        //API Methods
        protected:
            //Access Functions

            /// Returns the number of permitted display modes.
            /** The returned number of display modes is referring to the current display, set by DisplayIndex. */
            static int GetAvailableVideoModes(lua_State *Lua) {
                int Results = 1;

                int GetAvailableVideoModes = 0;

                if (Application) {
                    GetAvailableVideoModes = Application->GetAvailableVideoModes();
                }

                lua_pushinteger(Lua, GetAvailableVideoModes);

                return Results;
            }

            /// Returns the framerate of the application.
            /** The framerate is measured and updated once every second. */
            static int GetFramerate(lua_State *Lua) {
                int Results = 1;
                int Framerate = 0;

                if (Application) {
                    Framerate = Application->GetFramerate();
                }

                lua_pushnumber(Lua, Framerate);

                return Results;
            }

            /// Returns the height of the application window.
            /** @param WindowMode If specified, the function will return the height for that window mode. If not specified, the height for the current window mode will be returned. */
            static int GetHeight(lua_State *Lua) {
                int Results = 1;
                int Height = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    int WindowMode = -1;

                    if (Arguments == 1) WindowMode = lua_tointeger(Lua, 1);
                    Height = Application->GetHeight(WindowMode);
                }

                lua_pushnumber(Lua, Height);

                return Results;
            }

            /// Returns the maximum allowed rate of input events.
            static int GetIPS(lua_State *Lua) {
                int Results = 1;
                int IPS = 0;

                if (Application) {
                    IPS = Application->GetIPS();
                }

                lua_pushinteger(Lua, IPS);

                return Results;
            }

            /// Returns the process speed of the main game loop.
            static int GetPPS(lua_State *Lua) {
                int Results = 1;
                int PPS = 0;

                if (Application) {
                    PPS = Application->GetPPS();
                }

                lua_pushinteger(Lua, PPS);

                return Results;
            }

            /// Returns the current runtime of the application in seconds.
            static int GetRuntime(lua_State *Lua) {
                int Results = 1;
                float Runtime = 0;

                if (Application) {
                    Runtime = Application->GetRuntime();
                }

                lua_pushnumber(Lua, Runtime);

                return Results;
            }

            /// Returns the VSync property.
            static int GetVSync(lua_State *Lua) {
                int Results = 1;
                bool VSync = 0;

                if (Application) {
                    VSync = Application->GetVSync();
                }

                lua_pushboolean(Lua, VSync);

                return Results;
            }

            /// Returns the WindowMode property.
            static int GetVideoMode(lua_State *Lua) {
                int Results = 1;

                std::string GetVideoMode;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        int i = lua_tointeger(Lua, 1);

                        GetVideoMode = Application->GetVideoMode(i);
                    } else std::cerr << "(Application/API.h) GetVideoMode(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                lua_pushstring(Lua, GetVideoMode.c_str());

                return Results;
            }

            /// Returns the width of the application window.
            /** @param WindowMode If specified, the function will return the width for that window mode. If not specified, the width for the current window mode will be returned. */
            static int GetWidth(lua_State *Lua) {
                int Results = 1;
                int Width = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    int WindowMode = -1;

                    if (Arguments == 1) WindowMode = lua_tointeger(Lua, 1);
                    Width = Application->GetWidth(WindowMode);
                }

                lua_pushnumber(Lua, Width);

                return Results;
            }

            /// Returns the WindowMode property.
            static int GetWindowMode(lua_State *Lua) {
                int Results = 1;
                int WindowMode = -1;

                if (Application) {
                    WindowMode = Application->GetWindowMode();
                }

                lua_pushinteger(Lua, WindowMode);

                return Results;
            }


            /// Used to check if a specified key is pressed.
            /** @param Key Uses the SDL_Scancode enumeration. Supports some custom definitions such as SDL_CUSTOM_SHIFT. */
            static int IsKeyPressed(lua_State *Lua) {
                int Results = 1;
                bool IsKeyPressed = false;

                int Arguments = lua_gettop(Lua);
                if (Arguments == 1) {
                    SDL_Scancode Key = (SDL_Scancode)lua_tointeger(Lua, 1);
                    if (Application) {
                        IsKeyPressed = Application->IsKeyPressed(Key);
                    }
                }

                lua_pushboolean(Lua, IsKeyPressed);

                return Results;
            }

            /// Converts a specified SDL_Scancode to text.
            /** Used to display different keys in UI menus.
                @param Key The SDL_Scancode to convert to text.
                @param Short When true, certain keys are made shorter, e.g. "Bkspc" is short for "Backspace". */
            static int SDLScancodeToText(lua_State *Lua) {
                int Results = 1;
                std::string Text;

                int Arguments = lua_gettop(Lua);
                if (Arguments == 1 || Arguments == 2) {
                    SDL_Scancode Key = (SDL_Scancode)lua_tointeger(Lua, 1);

                    bool Short = false;
                    if (Arguments == 2) Short = lua_toboolean(Lua, 2);

                    if (Application) {
                        Text = Application->SDLScancodeToText(Key, Short);
                    }
                }

                lua_pushstring(Lua, Text.c_str());

                return Results;
            }

            //Process Functions

            /// Enables or disables resizing of the application window.
            static int AllowResize(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        bool Resizable = lua_toboolean(Lua, 1);

                        Application->AllowResize(Resizable);
                    } else std::cerr << "(Application/API.h) AllowResize(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Applies current video mode settings.
            static int ApplyVideoMode(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    Application->ApplyVideoMode();
                }

                return Results;
            }

            /// Saves a screenshot at the specified location.
            /** The filename of the saved screenshot is in the following format: YYYYMMDDHHmmss */
            static int SaveScreenshot(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        std::string Location = lua_tostring(Lua, 1);
                        Application->SaveScreenshot(Location);
                    } else std::cerr << "(Application/API.h) SaveScreenshot(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Sets the maximum allowed inputs per second.
            static int SetIPS(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        int IPS = lua_tointeger(Lua, 1);

                        Application->SetIPS(IPS);
                    } else std::cerr << "(Application/API.h) SetIPS(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Sets the intended process speed for the application.
            static int SetPPS(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        int PPS = lua_tointeger(Lua, 1);

                        Application->SetPPS(PPS, 5); //TEMP
                    } else std::cerr << "(Application/API.h) SetPPS(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }


            /// Sets the width and height of the application.
            /** @param Width, Height The specified resolution.
                @param WindowMode The window mode for which the resolution is intended. If not specified, the current window mode is used. */
            static int SetResolution(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments <= 2) {
                        std::string Resolution = lua_tostring(Lua, 1);
                        int Width = Strings::StringTo<int>(Resolution, 'x');
                        int Height = Strings::StringTo<int>(Resolution, 'x', 1);
                        int WindowMode = -1;

                        if (Arguments == 2) WindowMode = lua_tointeger(Lua, 2);

                        Application->SetResolution(Width, Height, WindowMode);
                    } else std::cerr << "(Application/API.h) SetResolution(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Sets the title of the window application.
            static int SetTitle(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        std::string Title = lua_tostring(Lua, 1);
                        Application->SetTitle(Title);
                    } else std::cerr << "(Application/API.h) SetTitle(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Sets the VSync option.
            static int SetVSync(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        bool VSync = lua_toboolean(Lua, 1);
                        Application->SetVSync(VSync);
                    } else std::cerr << "(Application/API.h) SetVSync(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Sets the window mode of the application.
            static int SetWindowMode(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        int WindowMode = lua_tointeger(Lua, 1);

                        Application->SetWindowMode(WindowMode);
                    } else std::cerr << "(Application/API.h) SetWindowMode(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Enables or disables the border of the application window.
            static int ShowBorder(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    int Arguments = lua_gettop(Lua);

                    if (Arguments == 1) {
                        bool Bordered = lua_toboolean(Lua, 1);

                        Application->ShowBorder(Bordered);
                    } else std::cerr << "(Application/API.h) ShowBorder(): Function called with invalid number of arguments (" << Arguments << ")." << std::endl;
                }

                return Results;
            }

            /// Stops the application from running.
            /** This function does not close the application window. */
            static int Stop(lua_State *Lua) {
                int Results = 0;

                if (Application) {
                    Application->Stop();
                }

                return Results;
            }
    };
}

#endif
