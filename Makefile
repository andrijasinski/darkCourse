#####################################################
# You may need to change the parameters under here. #
#####################################################

# Step 1: Choose a compiler. By default, use clang++

# If you use clang++, make sure the following line does not start with a comment (#)
CXX=clang++
# If you use g++, uncomment the following line
#CXX=g++

# Set default compiler parameters
# -Wall 	shows all warnings when compiling, always use this!
# -std=c++11 	enables the C++11 standard mode
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Compiler flag -Idir specifies, that there are includes in the 'dir' directory
# LIB_CXXFLAGS = $(CXXFLAGS) -Iinclude

# Step 2: If you use clang++ under Mac OS X, remove these comments
#CXXFLAGS += -stdlib=libc++
#LFLAGS += -stdlib=libc++

# Step 3: Run 'make' in the same directory as this file

########################################################
# You need to make changes below here to solve Task 2. #
########################################################

# Declare the name of our program (in Windows, the compiler adds .exe)
PROGRAM = bin/game.out

# The needed object files (we make these from the source code)
OBJ = obj/main.o

# This is the first target. It will be built when you run 'make' or 'make build'
build: $(PROGRAM)

# Rule for linking IMPORTANT! The space in front of $(CXX) is a TABULATOR!
$(PROGRAM): $(OBJ)
	$(CXX) $(OBJ) $(LFLAGS) -o $(PROGRAM)

# Rules for compiling
obj/main.o: src/main.cpp
	$(CXX) -c src/main.cpp -o obj/main.o $(CXXFLAGS)

clean:
	rm -f bin/*
	rm -f lib/*
	rm -f obj/*
	rm -rf docs/*