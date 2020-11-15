CC = gcc
CFLAGS = -Wall

queueTester-circular: queueTester-circular.o queue-circular_int.o
	$(CC) $(CFLAGS) -o queueTester-circular queueTester-circular.o queue-circular_int.o

queueTester-list: queueTester-list.o queue-list_int.o
	$(CC) $(CFLAGS) -o queueTester-list queueTester-list.o queue-list_int.o

queueTester-circular.o: queueTester-circular.c boundedQueue.h queue.h
	$(CC) $(CFLAGS) -o queueTester-circular.o -c queueTester-circular.c 

queueTester-list.o: queueTester-list.c boundedQueue.h queue.h
	$(CC) $(CFLAGS) -o queueTester-list.o -c queueTester-list.c 

queue-circular_int.o: queue-circular.c boundedQueue.h queue.h
	$(CC) $(CFLAGS) -o queue-circular_int.o -c queue-circular.c -DCUSTOM_TYPE="int"

queue-list_int.o: queue-list.c unboundedQueue.h queue.h
	$(CC) $(CFLAGS) -o queue-list_int.o -c queue-list.c -DCUSTOM_TYPE="int"

clean:
	rm -f *.o queueTester-list queueTester-circular
