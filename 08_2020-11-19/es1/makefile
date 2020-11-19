CC = gcc
# CFLAGS = -Wall -g -DEBUG -DCUSTOM_TYPE="int"
CFLAGS = -Wall -DCUSTOM_TYPE="int"

randomTree: main.o bitree.o
	$(CC) $(CFLAGS) -o randomTree main.o bitree.o

main.o: main.c bitree.h item.h
	$(CC) $(CFLAGS) -c main.c

bitree.o: bitree.c bitree.h item.h
	$(CC) $(CFLAGS) -c bitree.c

clean:
	rm -f *.o randomTree
