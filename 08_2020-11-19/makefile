CC = gcc
CFLAGS = -Wall
# CFLAGS = -Wall -g -DEBUG

es8: randomTree wordMap

randomTree: randomTree.o bitree.o
	$(CC) $(CFLAGS) -o randomTree randomTree.o bitree.o

randomTree.o: 1-randomTree.c ../include/bitree.h
	$(CC) $(CFLAGS) -c -o randomTree.o 1-randomTree.c

wordMap: wordMap.o bitree.o bistree.o
	$(CC) $(CFLAGS) -o wordMap wordMap.o bitree.o bistree.o

wordMap.o: 2-wordMap.c ../include/bistree.h ../include/bitree.h
	$(CC) $(CFLAGS) -c -o wordMap.o 2-wordMap.c

bitree.o: ../src/bitree.c ../include/bitree.h
	$(CC) $(CFLAGS) -c ../src/bitree.c

bistree.o: ../src/bistree.c ../include/bistree.h
	$(CC) $(CFLAGS) -c ../src/bistree.c

clean:
	rm -f *.o randomTree wordMap
