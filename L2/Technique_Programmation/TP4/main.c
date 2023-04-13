#include <stdio.h>
#include <stdlib.h>
#include "library.h"

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