#include "book.h"
#include "library.h"
int main(){
  library_t Sciences_Library;
  library_t Novel_Library;
  book_t book1, book2, book3, book4;

  Sciences_Library.set_name("Sciences Library");
  Sciences_Library.add_day(monday);
  Sciences_Library.add_day(tuesday);
  Sciences_Library.add_day(wednesday);
  Sciences_Library.add_day(thursday);

  Novel_Library.set_name("Novel Library");
  Novel_Library.add_day(tuesday);
  Novel_Library.add_day(wednesday);
  Novel_Library.add_day(thursday);
  Novel_Library.add_day(friday);

  book1.set_name("The C++ Programming Language");
  book1.set_publisher("Addison-Wesley");
  book1.set_year(2013);
  book1.set_isbn(780321563842);
  book1.add_author("Bjarne Stroustrup");

  book2.set_name("C++: The Complete Reference");
  book2.set_publisher("McGraw-Hill");
  book2.set_year(2003);
  book2.set_isbn(9780070532465);
  book2.add_author("Herbert Schildt");

  book3.set_name("Harry Potter and the Philosopher's Stone");
  book3.set_publisher("Bloomsbury");
  book3.set_year(1997);
  book3.set_isbn(9780747532699);
  book3.add_author("J. K. Rowling");

  book4.set_name("Harry Potter and the Chamber of Secrets");
  book4.set_publisher("Bloomsbury");
  book4.set_year(1998);
  book4.set_isbn(9780747538493);
  book4.add_author("J. K. Rowling");

  

  Sciences_Library.add_book(book1);
  Sciences_Library.add_book(book2);
  Novel_Library.add_book(book3);
  Novel_Library.add_book(book4);
  Sciences_Library.print();
  Novel_Library.print();
  return 0;
}
