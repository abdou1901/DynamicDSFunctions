CC=gcc
CFLAGS=-Wall -g

all: TestFile

TestFile: TestFile.c circularLinkedLists.c
	$(CC) $(CFLAGS) -o TestFile TestFile.c circularLinkedLists.c

clean:
	rm -f TestFile