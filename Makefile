run: main.o course.h
	g++ -o run main.o
main.o: main.cpp course.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean:
	rm *.o run
