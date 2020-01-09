all: compile run

compile:
	g++ *.cpp -o tri.exe

run:
	tri.exe
