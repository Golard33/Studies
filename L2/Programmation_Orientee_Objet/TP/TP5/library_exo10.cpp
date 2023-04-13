#include <algorithm> // for sort
#include <iostream> // for cout
using namespace std; // for cout
#include <limits> // for numeric_limits
#include <vector>
using namespace std;

enum day_t {
  monday = 0, tuesday, wednesday, thursday, friday, saturday, sunday
};

class book_t {
  const char *name;
  vector<const char*> authors;
  int nauthors;
  const char *publisher;
  int year;
  long isbn;
  public:
    book_t(){
      this->name = NULL;
      this->nauthors = 0;
      this->publisher = NULL;
      this->year = 0;
      this->isbn = 0;
    }
    ~book_t(){}
    void print() const{
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
    void add_author(const char *author){
      this->authors.resize(this->nauthors+1);
      this->authors[this->nauthors] = author;
      this->nauthors++;
    }
    void set_name(const char *name){
      this->name = name;
    }
    void set_publisher(const char *publisher){
      this->publisher = publisher;
    }
    void set_year(int year){
      this->year = year;
    }
    void set_isbn(long isbn){
      this->isbn = isbn;
    }
    long get_isbn(){
        return this->isbn;
    }
};

class library_t {
  const char *name;
  vector<day_t> days;
  int ndays;
  vector<book_t> books;
  int nbooks;
  public:
    library_t(){
      this->name = NULL;
      this->ndays = 0;
      this->nbooks = 0;
    }
    ~library_t(){}
    void print() const{
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
    void add_day(day_t day){
      this->days.resize(this->ndays+1);
      this->days[this->ndays] = day;
      this->ndays++;
    }
    void add_book(book_t book){
      this->books.resize(this->nbooks+1);
      this->books[this->nbooks] = book;
      this->nbooks++;
    }
    void set_name(const char *name){
      this->name = name;
    }
    vector<long> get_isbns(){
      vector<long> isbns;
        isbns.resize(this->nbooks);
        for(int i;i<this->nbooks;i++){
            isbns[i]=this->books[i].get_isbn();
        }
        return isbns;
    };

};

int main(){
  library_t Sciences_Library;
  library_t Novel_Library;
  book_t book1, book2, book3, book4;
  vector<long> isbns;
  vector<long>::iterator il;

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
  book1.set_isbn(9780321563842);
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
  isbns=Sciences_Library.get_isbns();
  cout<<"Not Sorted"<<endl;
  for(il=isbns.begin();il!=isbns.end();il++){
    cout<<*il<<endl;
  }
  sort(isbns.begin(),isbns.end());
  cout<<"Not Sorted"<<endl;

  for(il=isbns.begin();il!=isbns.end();il++){
    cout<<*il<<endl;
  }
  return 0;
}
