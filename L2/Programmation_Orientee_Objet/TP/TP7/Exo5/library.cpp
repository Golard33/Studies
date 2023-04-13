#include "library.h"
#include <iostream> // for cout
using namespace std; // for cout
library_t::library_t(){
  this->name = NULL;
  this->ndays = 0;
  this->nbooks = 0;
}
library_t::~library_t(){}
void library_t::print() {
  int i;
  char day[7][10] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
  cout<<"(\""<<this->name<<"\", ";
  cout<<"(";
  for (i = this->days[0]; i < (this->ndays+this->days[0]); i++) {
    i != ((this->ndays+this->days[0])-1) ? cout<<"\""<<day[i]<<"\", " : cout<<"\""<<day[i]<<"\"), ";
  }
  cout<<"(";
  for (i = 0; i < this->nbooks; i++) {
    books[i].print();
    if(i != this->nbooks-1) cout<<", ";
  }
  cout<<")"<<endl;
}
void library_t::add_day(day_t day){
  this->days.resize(this->ndays+1);
  this->days[this->ndays] = day;
  this->ndays++;
}
void library_t::add_book(book_t book){
  this->books.resize(this->nbooks+1);
  this->books[this->nbooks] = book;
  this->nbooks++;
}
void library_t::set_name(const char *name){
  this->name = name;
}
