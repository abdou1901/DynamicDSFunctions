CC=gcc
CFLAGS=-Wall -g -IPART\ I -IPART\ II

all: TestFile

TestFile: TestFile.c PART\ I/Recursion_1.c PART\ II/Recursion_2.c
	$(CC) $(CFLAGS) -o TestFile TestFile.c PART\ I/Recursion_1.c PART\ II/Recursion_2.c

clean:
	rm -f TestFile