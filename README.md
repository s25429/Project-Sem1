# Snake Game in C++
> School project for 1st semester - Snake Game in C++\
> Works on Linux and Windows

## Table of Contents
* [General Information](#general-information)
* [Screenshots](#screenshots)
* [Build and Run](#build-and-run)
* [Project Status](#project-status)
* [Known Issues](#known-issues)
* [Possible Improvements](#possible-improvements)
* [Contact](#contact)

## General Information
Snek The Game 2.0 is a simple game wrote in C++17 that launches and plays in the console window. It can be compiled and ran on both Linux, Windows and probably also Mac (but not tested on it, should work though). It was made as an university project for the first semester.\
For now the TXT files scoreboard.txt and config.txt do not do anything important, but they have to be present. They are there for future plans.

## Screenshots
![Image-1](./imgs/img1.png?raw=true)
![Image-2](./imgs/img2.png?raw=true)
![Image-3](./imgs/img3.png?raw=true)

## Build and Run

### 1. Basic setup and explanation of the contents
First you need to properly setup the environment. How you will set it up depends on the method of compiling the project. Build was tested for compilation errors using g++ with Makefile on Linux and using built-in compiler in Visual Studio 2019 on Windows 10.\

Files and folders explanation:
- main.cpp - this is the main file that needs to be compiled. It can be compiled into any name one wishes,
- \*.txt - files that need to be in the same directory as already compiled main file, eg. main.bin is located where those two TXT files are,
- api, templates, utils - these are folders with CPP files that are needed for compilation only.

### 2. Ways of building and running for different platforms
There are few ways to build the program, as it works on Windows and Linux:

#### - Compiling with g++
First you clone the repository, then get inside and launch the command: `g++ -std=c++17 main.cpp -o main.bin`. Then launching it is as simple as `./main.bin`. If for some reason you cannot either compile or launch the executable, try giving to both files proper privilages: `chmod 755 [main.cpp|main.bin]`.

#### - Compiling with Makefile
This is the way I have compiled it on Linux. You have to put Everything into src folder, but the TXT files. Those have to go to build folder. From atop those two folders you compile main.cpp and run the output with this command: `make build/main.bin && ./build/main.bin`.\
The tree of the folders and files should look like this:\
|- src\
| &nbsp; |- api\
| &nbsp; |- templates\
| &nbsp; |- utils\
| &nbsp; \\- main.cpp\
|- build\
| &nbsp; |- config.txt\
| &nbsp; |- scoreboard.txt\
| &nbsp; \\- main.bin\
|- Makefile\
|- LICENSE\
\\- README.md

#### - Compiling in Visual Studio
There is probably a clean way of doing it but I did it the most braindead way. Simply create a new project, create new CPP file and paste into it the contents of main.cpp. Then open the project location in file explorer and paste folders api, templates and utils where the main CPP file is. Then paste TXT files into Debug folder where the EXE file will be after compilation. After that you simply compile and run from Visual Studio window and it should all work.\
Alternatively you can use either other IDEs or g++ on Windows, or something like that. For the latter, follow the instruction for Compiling with g++.

## Project Status
Technically the project is complete and working, although I would like to add some functionality listed below:
- Support for Extended ASCII Codes in Options menu,
- Reading configuration from a file for user-editable settings,
- Scoreboard being stored as a file,
- Options menu as a whole, currently it doesn'y exist.

## Known Issues
As with any project, there might be some smaller and bigger issues. Here is a list of those that I know of:
- On Windows there are flashings between the refreshing between previous and next screen.,
- On Linux there are sometimes huge spikes of refresh rate for some reason. Not sure why exactly, as same issue wasn't noted on Windows machine.

## Possible Improvements
- Using ncurses library for better refresh and update management of windows (pdcurses for Windows),
- Updating the game's UI to show current score and maybe direction where snake is going,
- Adding an instruction on how to move around and basic info about the game's goal,
- Adding a way to change keybindings.

## Contact
Created by s25429 AKA [ThatHoracy](https://github.com/ThatHoracy), but currently posted on an account using school email (this one!)
- School e-mail: s25429@pjwstk.edu.pl\
If you wish to contact me for something else than school related things (like work offer or chit-chat):
- Business e-mail: cezary.cislak@gmail.com
