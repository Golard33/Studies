#include <stdio.h>

typedef struct 
{

    char name[100];
    char authors[10][100];
    int nauthors;
    char publisher [100];
    int year;
    long isbn;
}book_t;

typedef enum 
{

    monday, tuesday, wednesday, thursday, friday, saturday,sunday
    

       
}day_t;

typedef struct 
{   
    char name[100];
    day_t day_e[7];
    int ndays;
    book_t books[100];
    int nbooks;
}library_t;




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



void library_print(library_t l)
{
    int i;
    char *day_str[] = {"monday", "tuesday", "wednesday", "thursday",
    "friday", "saturday", "sunday"};
    printf("(");
    printf("\"%s\", ", l.name);
    printf("(");
    for(i=0;i<l.ndays-1;i++){
        printf("\"%s\", ", day_str[l.day_e[i]]);
    }
    
    printf("\"%s\" , " ,day_str[l.day_e[i]]);
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


int main()
{
    library_t SciencesLibrary =
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
    };
    library_print(SciencesLibrary);
    library_print(NovelLibrary);
    return 0;
}