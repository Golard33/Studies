#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"



enum day_t {
  monday = 0, tuesday, wednesday, thursday, friday, saturday, sunday
};
class library_t {
  const char *name;
  vector<day_t> days;
  int ndays;
  vector<book_t> books;
  int nbooks;
  public:
    library_t();
    ~library_t();
    void print();
    void add_day(day_t day);
    void add_book(book_t book);
    void set_name(const char *name);
};
#endif
