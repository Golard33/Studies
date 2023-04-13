#ifndef BOOK_H
#define BOOK_H
#include <limits> // for numeric_limits
#include <vector>
using namespace std; // for cout

class book_t{
    const char *name;
  vector<const char*> authors;
  int nauthors;
  const char *publisher;
  int year;
  long isbn;
  public:
    book_t();
    ~book_t();
    void print() const;
    void add_author(const char *author);
    void set_name(const char *name);
    void set_publisher(const char *publisher);
    void set_year(int year);
    void set_isbn(long isbn);



};
#endif
