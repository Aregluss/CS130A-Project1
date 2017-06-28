INCLUDE = HashTable.h Heap.h HeapHashTable.h HTNode.h

all : prog1

prog1: main.o
	g++ main.o -o prog1

main.o: main.cpp $(INCLUDE)
	g++ -c -g main.cpp

clean:
	rm -f *.o prog1