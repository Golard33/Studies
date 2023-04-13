#include <iostream> // for cout
using namespace std; // for cout
#include "book.h"
book_t::book_t(){
  this->name = NULL;
  this->nauthors = 0;
  this->publisher = NULL;
  this->year = 0;
  this->isbn = 0;
}

book_t::~book_t(){}

void book_t::print() const{
  int i;
  cout<<"(\""<<this->name<<"\", ";
  cout<<"(";
  for (i = 0; i < this->nauthors; i++) {
    cout<<"\""<<this->authors[i]<<"\"";
  }
  cout<<"), ";
  cout<<"\""<<this->publisher<<"\", ";
  cout<<this->year<<", ";
  cout<<this->isbn;
}
void book_t::add_author(const char *author){
  this->authors.resize(this->nauthors+1);
  this->authors[this->nauthors] = author;
  this->nauthors++;
}
void book_t::set_name(const char *name){
  this->name = name;
}
void book_t::set_publisher(const char *publisher){
  this->publisher = publisher;
}
void book_t::set_year(int year){
  this->year = year;
}
void book_t::set_isbn(long isbn){
  this->isbn = isbn;
}
