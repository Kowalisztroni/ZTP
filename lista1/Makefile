all: prog1 prog2

prog1: src/prog1/main.o lib/hello/hello.o
	g++ -o prog1 src/prog1/main.o lib/hello/hello.o

prog2: src/prog2/main.o lib/hello/hello.o
	g++ -o prog2 src/prog2/main.o lib/hello/hello.o

lib/hello/hello.o: lib/hello/hello.cpp
	g++ -c lib/hello/hello.cpp -o lib/hello/hello.o

src/prog1/main.o: src/prog1/main.cpp
	g++ -c src/prog1/main.cpp -o src/prog1/main.o

src/prog2/main.o: src/prog2/main.cpp
	g++ -c src/prog2/main.cpp -o src/prog2/main.o

