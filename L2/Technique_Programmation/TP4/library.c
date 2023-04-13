#include <stdio.h>
#include <stdlib.h>
#include "library.h"


void library_print(library_t l)
{
    char *day_str[] = 
{
    "monday", "tuesday", "wednesday", "thursday",
    "friday", "saturday", "sunday"
};
    int i;
    printf("(");
    printf("\"%s\", ", l.name);
    printf("(");
    for(i=0;i<l.ndays-1;i++){
        printf("\"%s\", ", day_str[l.days[i]]);
    }
    
    printf("\"%s\" , " ,day_str[l.days[i]]);
    printf("), (");
    for(i=0; i<l.nbooks;i++){
        book_print(l.books[i]);
        if (i != l.nbooks-1){
            printf("), ");
        }else{
            printf(")))\n");
        }
    }
}

library_t* library_create ()
{
    library_t *library;
    library = malloc(sizeof(library_t));
    if ( library == NULL){
        return NULL;
    }
    library -> name = NULL;
    library -> days = NULL;
    library -> ndays = 0;
    library -> books = NULL;
    library -> nbooks = 0;


    return library;

}

void library_free(library_t *library){

    free(library);
}

int library_add_day(library_t *library, day_t day){

    library -> days = realloc(library -> days, sizeof(day_t)*(library -> ndays+1));
    if ( library-> days == NULL ){
        return -1;
    }
    library -> days[library -> ndays]=day;
    library -> ndays+=1;
    return 0;
}


int library_add_book(library_t *library, book_t book){

    library -> books = realloc(library -> books, sizeof(book_t)*(library -> nbooks+1));
    if ( library -> books == NULL){
        return -1;
    }
    library -> books[library -> nbooks]=book;
    library -> nbooks+=1;
    return 0;
}
