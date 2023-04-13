all: bm.out

base.o: base.c base.h
	gcc -std=c89 -pedantic -Wall -Werror -g `pkg-config libxml-2.0 --cflags` -c -o base.o base.c

facility.o: facility.c facility.h
	gcc -std=c89 -pedantic -Wall -Werror -g `pkg-config libxml-2.0 --cflags` -c -o facility.o facility.c

library.o: library.c library.h
	gcc -std=c89 -pedantic -Wall -Werror -g `pkg-config libxml-2.0 --cflags` -c -o 

bm.out: bm.c base.o facility.o
	gcc -std=c89 -pedantic -Wall -Werror -g `pkg-config libxml-2.0 --cflags` -o bm.out bm.c base.o facility.o `pkg-config libxml-2.0 --libs-only-L` `pkg-config libxml-2.0 --libs-only-l`
clean:
	rm -fv *.o *.out
