run: main.o interfaces.o filter.o course.o
	g++ -o run main.o interfaces.o filter.o course.o
course.o: course.cpp course.h
	g++ -c -Wall -pedantic -g -std=c++11 course.cpp
filter.o: filter.cpp course.h
	g++ -c -Wall -pedantic -g -std=c++11 filter.cpp
interfaces.o: interfaces.cpp interfaces.h filter.h
	g++ -c -Wall -pedantic -g -std=c++11 interfaces.cpp
main.o: main.cpp course.h interfaces.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean:
	rm *.o run
