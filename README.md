# platform

This repository roughly contains the game-engine and [my other repository](https://github.com/Bjeeeern/handmade) 
contains the game-code for the "handmade" game built on-top. The idea is that I will re-use this repository for developing other applications down-the-road. Everything in both of the repositories is written by hand by me apart from a couple of functions in math.h that I will revisit once I start optimizing things.

The design follows the way it is done in the Handmade Hero web series. In short, the game is broken up into an executable part that is rewritten for every platform and a library file that gets loaded at runtime, containing the rest of the engine/game logic.

The windows executable is compiled from the win32_platform.cpp.

<img src="promo_data/Win32PlatformDemonstration.gif" width="800" />
