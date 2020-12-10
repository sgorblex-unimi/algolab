CC = gcc
CFLAGS = -Wall
# CFLAGS = -Wall -g -DEBUG

es10: scheduling

scheduling: scheduling.o heap.o
	$(CC) $(CFLAGS) -o scheduling scheduling.o heap.o

scheduling.o: 1-scheduling.c ../include/heap.h
	$(CC) $(CFLAGS) -c -o scheduling.o 1-scheduling.c

heap.o: ../src/heap.c ../include/heap.h
	$(CC) $(CFLAGS) -c ../src/heap.c

clean:
	rm -f *.o scheduling

