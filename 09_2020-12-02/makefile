CC = gcc
CFLAGS = -Wall
# CFLAGS = -Wall -g -DEBUG

es9: heapSort

heapSort: heapSort.o heap.o
	$(CC) $(CFLAGS) -o heapSort heapSort.o heap.o

heapSort.o: 1-heapSort.c ../include/heap.h ../include/pqueue.h
	$(CC) $(CFLAGS) -c -o heapSort.o 1-heapSort.c

heap.o: ../src/heap.c ../include/heap.h
	$(CC) $(CFLAGS) -c ../src/heap.c

clean:
	rm -f *.o heapSort
