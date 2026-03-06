students: main.o date.o address.o student.o
		g++ -g main.o date.o address.o -o students

main.o: main.cpp date.h address.h student.h
		g++ -g -c main.cpp

date.o: date.cpp date.h
		g++ -g -c date.cpp

address.o: address.cpp address.h
		g++ -g -c address.cpp

student.o: student.cpp student.h date.h address.h
		g++ -g -c student.cpp

run: students
		./students

clean:
		rm students
		rm *.o

debug: students
		gdb students

valgrind: students
		valgrind --leak-check#=full ./students