all: compile run
compile:
	g++ main.cpp Matrix/*.cpp
run:
	./a.exe
