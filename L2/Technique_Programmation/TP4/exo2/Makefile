all: main.out

main.o: main.c
	gcc -std=c89 -pedantic -Wall -Werror -g -c -o main.o main.c

book.o: book.c book.h
	gcc -std=c89 -pedantic -Wall -Werror -g -c -o book.o book.c

library.o: library.c library.h
	gcc -std=c89 -pedantic -Wall -Werror -g -c -o library.o library.c

main.out: main.o book.o library.o
	gcc -std=c89 -pedantic -Wall -Werror -g -o main.out main.o book.o library.o
	
clean:
	rm -fv *.o *.out
