CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic

all: stack.o main.o
	$(CC) $(CFLAGS) main.o stack.o -o a.out

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o *.out
