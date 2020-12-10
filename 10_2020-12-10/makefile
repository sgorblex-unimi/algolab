CC = gcc
CFLAGS = -Wall
# CFLAGS = -Wall -g -DEBUG

es10: scheduling simpleBag

scheduling: scheduling.o heap.o
	$(CC) $(CFLAGS) -o scheduling scheduling.o heap.o

scheduling.o: 1-scheduling.c ../include/heap.h
	$(CC) $(CFLAGS) -c -o scheduling.o 1-scheduling.c

simpleBag: simpleBag.o
	$(CC) $(CFLAGS) -o simpleBag simpleBag.o heap.o

simpleBag.o: 2-simpleBag.c
	$(CC) $(CFLAGS) -c -o simpleBag.o 2-simpleBag.c

heap.o: ../src/heap.c ../include/heap.h
	$(CC) $(CFLAGS) -c ../src/heap.c

clean:
	rm -f *.o scheduling simpleBag

