run: main.o course.o
	g++ -o run main.o course.o
course.o: course.cpp course.h
	g++ -c -Wall -pedantic -g -std=c++11 course.cpp
main.o: main.cpp course.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean:
	rm main.o course.o run
