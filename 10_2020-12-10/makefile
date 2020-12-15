CC = gcc
CFLAGS = -Wall
# CFLAGS = -Wall -g -DEBUG

es10: scheduling simpleBag bag scheduling2

scheduling: scheduling.o heap.o
	$(CC) $(CFLAGS) -o scheduling scheduling.o heap.o

scheduling.o: 1-scheduling.c ../include/heap.h
	$(CC) $(CFLAGS) -c -o scheduling.o 1-scheduling.c

simpleBag: simpleBag.o
	$(CC) $(CFLAGS) -o simpleBag simpleBag.o

simpleBag.o: 2-1-simpleBag.c
	$(CC) $(CFLAGS) -c -o simpleBag.o 2-1-simpleBag.c

bag: bag.o
	$(CC) $(CFLAGS) -o bag bag.o

bag.o: 2-2-bag.c
	$(CC) $(CFLAGS) -c -o bag.o 2-2-bag.c

scheduling2: scheduling2.o
	$(CC) $(CFLAGS) -o scheduling2 scheduling2.o heap.o

scheduling2.o: 3-scheduling2.c
	$(CC) $(CFLAGS) -c -o scheduling2.o 3-scheduling2.c

heap.o: ../src/heap.c ../include/heap.h
	$(CC) $(CFLAGS) -c ../src/heap.c

clean:
	rm -f *.o scheduling simpleBag bag scheduling2

