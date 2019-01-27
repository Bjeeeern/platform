# platform

This repository roughly contains the game-code and [my other repository](https://github.com/Bjeeeern/platform) 
contains the game-engine. The repository is named after the quite amazing [Handmade Hero](https://handmadehero.org/) web series
which I am working my way through, learning how to make this stuff. Everything in both of the repositories is written by hand by me apart from a couple of functions in math.h that I will revisit once I start optimizing things.

Below is an example of the engine loading and unloading entities as the camera move around. The world is an "as large as you want" hash mapping from world coordinates to blocks of entities. When entities move about they jump from block to block.

<img src="promo_data/Win32PlatformDemonstration.gif" width="800" />
