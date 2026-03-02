students: main.o date.o
		g++ -g main.o date.o -o students

main.o: main.cpp date.h
		g++ -g -c main.cpp

date.o: date.cpp date.h
		g++ -g -c date.cpp

run: students
		./students

clean:
		rm students
		rm *.o

debug: students
		gdb students

valgrind: students
		valgrind --leak-check#=full ./students