all: main.out

CC=gcc
CFLAGS= -std=c89 -pedantic -Wall -Werror -g
LDFLAGS=
LDLIBS=
RM= rm -fv

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

book.o: book.c book.h
	$(CC) $(CFLAGS) -c -o $@ $<

library.o: library.c library.h
	$(CC) $(CFLAGS) -c -o $@ $<

main.out: main.o book.o library.o
	$(CC) $(CFLAGS) -o $@ $^
	$(LDFLAGS) $(LDLIBS)
	
clean:
	$(RM) *.o *.out
