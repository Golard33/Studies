CC=gcc
CFLAGS=-Wall -pedantic-errors


PROTOCOL=tcp
PORT=45640
HOST=localhost



all: Serveur Client

Serveur: server.c $(PROTOCOL).c
	$(CC) -o Serveur server.c ${PROTOCOL}.c $(CFLAGS)

Client: client.c $(PROTOCOL).c
	$(CC) -o Client client.c ${PROTOCOL}.c $(CFLAGS)

clean:
	rm Serveur
	rm Client

init: all
	./Serveur $(PORT) & sleep .1 && ./Client $(HOST) $(PORT)