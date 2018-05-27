# darkCourse

The "darkCourse" is step-by-step RPG made as a project for C++ course in the University of Tartu.

## Requirements

To build this application, you will need a `clang++` or `g++` compilers. The `Makefile` uses `clang++` compiler by default and if you want to use `g++`, change `CXX` flag to `g++` in `Makefile`.

## Build

To compile and run the game execute following commands and follow in-game instructions:

```sh
cd path/to/darkCourse
make build
./bin/game.out
make clean # to clean folders
```