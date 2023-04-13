#ifndef BOOK_H
#define BOOK_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    char *name;
    char **authors;
    int nauthors;
    char *publisher;
    int year;
    long isbn;
}book_t;

void book_print( book_t b);
book_t* book_create ();
void book_free(book_t *books);
int book_add_author(book_t *books, char* author);
#endif