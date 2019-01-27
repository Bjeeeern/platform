# platform

This repository roughly contains the game-engine and [my other repository](https://github.com/Bjeeeern/handmade) 
contains the game-code for the "handmade" game built on-top. The idea is that I will re-use this repository for developing other applications down-the-road. Everything in both of the repositories is written by hand by me apart from a couple of functions in math.h that I will revisit once I start optimizing things.

The design follows the way it is done in the Handmade Hero web series. In short, the game is broken up into an executable part that is rewritten for every platform and a library file that gets loaded at runtime, containing the rest of the engine/game logic.

The windows executable is compiled from the win32_game.cpp.
Similarly the OSX gets compiled out from osx_game.mm and the Android apk natively from android_game.cpp. I have some old ports of the platform-layer that did the game-loop, memory allocation, input handling and pushing the framebuffer out to the screen. Debugging on Android and even OSX is a bit more involved though so I want to wait until I have more of a game to port before I write/rewrite new ports.

The interface between the executable and the library file is defined in platform.h. The idea is that the executable provides and tracks all the input and state of the program and that the library file is just logic that gets called on demand to further the program state.
functions like GAME_UPDATE_AND_RENDER and GAME_GET_SOUND_SAMPLES takes in input and state and produces audio and visual output.

The only exception happens in intrinsic.h where all the CPU and compiler specific optimizations gets collected. The rest of the fuctionality are just an assortment of h-files, some building upon others.


<img src="promo_data/Win32PlatformDemonstration.gif" width="800" />
