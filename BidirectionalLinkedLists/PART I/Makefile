CC=gcc
CFLAGS=-Wall -g

all: TestFile

TestFile: TestFile.c bidirectionalLinkedLists.c
	$(CC) $(CFLAGS) -o TestFile TestFile.c bidirectionalLinkedLists.c
clean:
	rm -f TestFile