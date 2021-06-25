CXX = emcc
OUTPUT = bin
INCLUDE = -I. -Iemscripten
CXXFLAGS = -g
EMSCRIPTEN_FLAGS = -s FETCH=1

all: main

main: src/main.cpp
	$(CXX) -o $(OUTPUT)/index.html $< $(CXXFLAGS) $(INCLUDE) $(EMSCRIPTEN_FLAGS)
