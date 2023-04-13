#include <stdio.h>
#include <stdlib.h>
#include "book.h"

void book_print( book_t b)
{
    int i;
    printf("(");
    printf("\"%s\", ", b.name);
    printf("(");
    for(i=0; i<b.nauthors-1;i++){
        printf("\"%s\", ", b.authors[i]);
    }
    printf("\"%s\"", b.authors[i]);
    printf("), ");
    printf("\"%s\", ", b.publisher);
    printf("%d, ", b.year);
    printf("%ld", b.isbn);
}

book_t* book_create ()
{
    book_t *books;
    books = malloc(sizeof(book_t));
    if ( books == NULL){
        return NULL;
    }
    books -> name = NULL;
    books -> authors = NULL;
    books -> nauthors = 0;
    books -> publisher = NULL;
    books -> year = 0;
    books -> isbn = 0;

    return books;

}


void book_free(book_t *books){

    free(books);
}

int book_add_author(book_t *books, char* author){

    books -> authors = realloc(books -> authors, sizeof(char*)*(books -> nauthors+1));
    if ( author == NULL){
        return -1;
    }
    books -> authors[books -> nauthors]=author;
    books -> nauthors++;
    return 0;
}