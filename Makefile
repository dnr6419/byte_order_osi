all: main

main: main.o
	g++ -o main main.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
clean:
	rm -f main *.o
