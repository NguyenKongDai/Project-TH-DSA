CC = g++

all: main.o SparseTable.o
	$(CC) main.o SparseTable.o -o main

SparseTable.o: SparseTable.h SparseTable.cpp
	$(CC) -g -c SparseTable.cpp

main.o: main.cpp SparseTable.h
	$(CC) -g -c main.cpp

clean:
	rm -f *.o
	rm main.exe