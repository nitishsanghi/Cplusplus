# System Monitor

This Udacity project is focussed on object oriented programming. The object of the project is to use principles of OOP to make a System Monitor akin to htop in linux or task manager in windows which can interactively display vital system resource and process information. The starter code was expanded to implement the `System`, `Process`, and `Processor` classes, as well as functions within the `LinuxParser` namespace. These class objects and functions were used to develop a pipeline to extract system information and display it in the terminal using the ncurses libraries for text-based graphical output. The result of the implementation is displayed in the gif below.

![Alt Text](https://media.giphy.com/media/IRvLVvSXxelCv806Fy/giphy.gif)

## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output. To install ncurses within your own Linux environment: `sudo apt install libncurses5-dev libncursesw5-dev`

## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts


