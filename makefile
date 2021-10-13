CC=gcc
CFLAGS=-g -Wall
OBJFLAGS=-g -Wall -c

targets=zombie lab6

all: $(targets)

zombie: zombie.c zombie.h
	$(CC) $(OBJFLAGS) $@.c

lab6: lab6.c zombie.o
	$(CC) $(CFLAGS) $@.c zombie.o -o $@

clean:
	rm *.o $(targets)