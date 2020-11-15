.DELETE_ON_ERROR:
CC = gcc
CFLAGS = -Wall
sortLauncher: sortLauncher.o 1-selectionSort.o 2-mergeSort.o swapArr.o
	$(CC) $(CFLAGS) -o sortLauncher sortLauncher.o 1-selectionSort.o 2-mergeSort.o swapArr.o

# %.o: %.c
	# $(CC) $(CFLAGS) -c $@

sortLauncher.o: sortLauncher.c mySort.h
	$(CC) $(CFLAGS) -c sortLauncher.c

selectionSort.o: 1-selectionSort.c mySort.h
	$(CC) $(CFLAGS) -c 1-selectionSort.c

mergeSort.o: 2-mergeSort.c mySort.h
	$(CC) $(CFLAGS) -c 2-mergeSort.c

swapArr.o: swapArr.c mySort.h
	$(CC) $(CFLAGS) -c swapArr.c


test: test.o 1-selectionSort.o 2-mergeSort.o swapArr.o
	$(CC) $(CFLAGS) -o test test.o 1-selectionSort.o swapArr.o 2-mergeSort.o

test.o: test.c
	$(CC) $(FLAGS) -c test.c

clean:
	rm -f 1-selectionSort.o 2-mergeSort.o sortLauncher.o swapArr.o test.o test sortLauncher
