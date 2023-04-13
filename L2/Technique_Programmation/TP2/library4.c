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

char *day_str[] = 
{
    "monday", "tuesday", "wednesday", "thursday",
    "friday", "saturday", "sunday"
};

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


void library_print(library_t l)
{
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

void book_free(book_t *books){

    free(books);
}

void library_free(library_t *library){

    free(library);
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



int main()
{
   /* library_t SciencesLibrary =
    {
        "Sciences Library",
        {monday, tuesday, wednesday, thursday},
        4,
        {
            {"The C Programming Language",
                {"Brian W. Kernighan", "Dennis M.Ritchie"},
                2,
                "Prentice Hall",
                1988,
                9780131103627
            },

            {"C: The Complete Reference",
                {"Herbert Schildt"},
                1,
                "McGraw-Hill Education",
                2000,
                9780072121247,
            }
        },
        2,
    };

    library_t NovelLibrary =
    {
        "Novel Library",
        {tuesday, wednesday, thursday, friday},
        4,
        {
            {
                "Harry Potter and the Philosopher's Stone",
                {"J. K. Rowling"},
                1,
                "Bloomsbury",
                1997,
                9780747532699
            },


            {
                "Harry Potter and the Chamber of Secrets",
                {"J. K. Rowling"},
                1,
                "Bloomsbury",
                1998,
                9780747538493,
            }
        },
        2
    };*/
    library_t* lib1;
    book_t* b1;

    lib1 = library_create();
    lib1 -> name = "sciences library";

    b1 = book_create();
    b1 -> name = "The C Programming Language";

    book_add_author( b1, "Brian W. Kernighan" );
    book_add_author( b1, "Dennis M.Ritchie" );
    library_add_day( lib1, monday);
    library_add_day( lib1, tuesday);
    library_add_day( lib1, wednesday);
    library_add_day( lib1, thursday);
    library_add_book( lib1, *b1);
    library_print (*lib1);

    return 0;
}