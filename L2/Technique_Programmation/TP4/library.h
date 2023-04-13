#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include "book.h"



typedef enum  
{

    monday, tuesday, wednesday, thursday, friday, saturday,sunday

}day_t;

typedef struct 
{   
    char *name;
    day_t *days;
    int ndays;
    book_t *books;
    int nbooks;
} library_t;

void library_print(library_t l);
library_t* library_create ();
void library_free(library_t *library);
int library_add_day(library_t *library, day_t day);
int library_add_book(library_t *library, book_t book);
#endif