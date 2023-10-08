CC = gcc
CFLAGS = -g -pthread -fPIC
LIBS =
JC = javac
JFLAGS = -g

all: client.out serveur.out main.out controle.out barman.out classes

client.out: client.c
	$(CC) $(CFLAGS) client.c -o client.out $(LIBS)

serveur.out: serveur.c tcp.c tcp.h
	$(CC) $(CFLAGS) serveur.c tcp.c -o serveur.out $(LIBS)

main.out: main.c fifo.c fifo.h tireuses.c tireuses.h
	$(CC) $(CFLAGS) main.c fifo.c tireuses.c -o main.out $(LIBS)

controle.out: controle.c tireuses.c tireuses.h
	$(CC) $(CFLAGS) controle.c tireuses.c -o controle.out $(LIBS)

barman.out: barman.c serveur.out controle.out main.out
	$(CC) $(CFLAGS) barman.c serveur.out controle.out main.out -o barman.out $(LIBS)

classes: Fournisseur.class Commande.class Biere.class IBiere.class

Fournisseur.class: Fournisseur.java
	$(JC) $(JFLAGS) Fournisseur.java

Commande.class: Commande.java
	$(JC) $(JFLAGS) Commande.java

Biere.class: Biere.java
	$(JC) $(JFLAGS) Biere.java

IBiere.class: IBiere.java
	$(JC) $(JFLAGS) IBiere.java

clean:
	rm -f client.out serveur.out main.out controle.out barman.out *.class
