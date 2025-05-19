CC=gcc
CFLAGS=-Wall -g

all: TestFile

TestFile: TestFile.c trees.c
	$(CC) $(CFLAGS) -o TestFile TestFile.c trees.c

clean:
	rm -f TestFile