all: main

main: main.o set.o
	g++ -Wall main.o set.o -o solution

main.o: main.cpp
	g++ -c main.cpp

set.o: set.h set.cpp
	g++ -c set.cpp

clean:
	rm -rf *o solution

run: main
	./solution
