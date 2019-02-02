run: main.o interfaces.o
	g++ -o run main.o interfaces.o
interfaces.o: interfaces.cpp interfaces.h
	g++ -c -Wall -pedantic -g -std=c++11 interfaces.cpp
main.o: main.cpp course.h interfaces.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean:
	rm *.o run
