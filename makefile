CC=gcc
CFLAGS=-g -Wall
OBJFLAGS=-g -Wall -c

targets=zombie lab6 multiples smallest difference sundays

all: $(targets)

zombie: zombie.c zombie.h
	$(CC) $(OBJFLAGS) $@.c

lab6: lab6.c zombie.o
	$(CC) $(CFLAGS) $@.c zombie.o -o $@

multiples: multiples.c
	$(CC) $(CFLAGS) $@.c -o $@

smallest: smallest.c
	$(CC) $(CFLAGS) $@.c -o $@

difference: difference.c
	$(CC) $(CFLAGS) $@.c -o $@

sundays: sundays.c
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm *.o $(targets)
