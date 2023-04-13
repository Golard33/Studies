preuvePileFile: Pile.o File.o preuvePileFile.o
	cc -o preuvePileFile preuvePileFile.o Pile.o File.o

Pile.o: Pile.h Pile.c
	cc -c Pile.c

File.o: File.h File.c
	cc -c File.c

preuvePileFile.o: Pile.h File.h preuvePileFile.c
	cc -c preuvePileFile.c

clean:
	rm *.o preuvePileFile
