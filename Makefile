.PHONY: clean

main: main.o num_of_existence_in_string.o
	g++ main.o num_of_existence_in_string.o -o main

num_of_existence_in_string.o: num_of_existence_in_string.cpp num_of_existence_in_string.h
	g++ -c num_of_existence_in_string.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main