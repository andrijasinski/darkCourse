CXX=clang++
CXXFLAGS = -Wall -std=c++14 -Iinclude

PROGRAM = bin/game.out
OBJ = obj/main.o

build: prebuild $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CXX) $(OBJ) $(LFLAGS) -o $(PROGRAM)

obj/main.o: src/main.cpp
	$(CXX) -c src/main.cpp -o obj/main.o $(CXXFLAGS)

prebuild:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*
	rm -f obj/*