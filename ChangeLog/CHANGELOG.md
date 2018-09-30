# Draconic Doom change log (Unreleased)

## [0.0.1] - 2018-09-15
### Changed
-Reorganized the DraconicDoom folder and moved it to a new repository

-Fixed typos/grammar in the readmes

### Added
-Added a project map image and linked it in our readme

## [0.0.2] - 2018-09-30
### Changed
-Switched Templhelpers.h from Player.h to Player.cpp

-Updated version for all files

-Showbanner call in gameloop.cpp moved to creator.cpp

-Fixed typos/grammar in the readmes

-Made the comments more readable/useful (removed redundant words/phrases, and aligned comments)

### Removed
-Saveload.h from creator.h (as specified in the project plan)

-sstream from temphelpers.h
  
-iostream from gameloop.cpp

-int argument exits from DraconicDoomLoop() in Creator.h/cpp

-iostream from saveload.cpp

-in Creator, redundant else statement in BattleMechanic, case5 runaway
