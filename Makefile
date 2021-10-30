CC = g++

all: main.o SparseTable.o
	$(CC) main.o SparseTable.o -o main

SparseTable.o: ./Week2/SparseTable.h ./Week2/SparseTable.cpp
	$(CC) -g -c ./Week2/SparseTable.cpp

main.o: main.cpp ./Week2/SparseTable.h
	$(CC) -g -c main.cpp

clean:
	rm -f *.o
	rm main.exe