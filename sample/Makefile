CC = g++
FLAGS = -std=c++0x

sample.bin:main.cpp supervisor.o object.o
	$(CC) main.cpp supervisor.o object.o -o sample.bin

supervisor.o:../src/supervisor.cpp ../src/supervisor.h
	$(CC) -c ../src/supervisor.cpp -o supervisor.o $(FLAGS)

object.o:
	$(CC) -c ../src/object.cpp -o object.o

clean:
	rm *.o

full-clean:clean
	rm sample.bin
