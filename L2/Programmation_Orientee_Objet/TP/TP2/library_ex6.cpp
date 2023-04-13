#include <cstdio> // for printf
#include <vector> // for vector
using namespace std; //for vector
enum day_t{
    monday, tuesday, wednesday, thursday, friday,saturday,sunday
};

char days_char[7][15] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

class doc_t {

  const char* name;
  int year;

  public:/*Constructeur qui intitialise a null et 0*/
    doc_t(){
      this->name = NULL;
      this->year = 0;
    }
    void set_name(const char* name){
      this->name = name;
    };

    void set_year(int year){
      this->year = year;
    };


    const char* get_name() const{
      return this->name;
    }

    int get_year() const{
      return this->year;
    }

    virtual void print() const = 0;
};

class audio_doc_t: virtual public doc_t  {
  int duration;

  public:
    audio_doc_t(){
      this->duration = 0;
    }

  void set_duration(long duration){
    this->duration = duration;
  }

  int get_duration() const{
    return this->duration;
  }

  virtual void print() const = 0;
};

class video_doc_t : virtual public doc_t{
    int duration;
    bool color_available;

  public:
    video_doc_t(){
      this->duration = 0;
      this->color_available = false;
    }
};
  class audio_tape_t : public audio_doc_t{
    public:
      void print() const {
         printf("Audio tape (\"%s\", %d, %d s)", get_name(), get_year(), get_duration() ) ;
      };
    };

    class audio_cd_t : public audio_doc_t{
    public:
      void print() const {
         printf("Audio cd (\"%s\", %d, %d s)", get_name(), get_year(), get_duration() ) ;
      };
    };

    void set_duration(long duration) {
      this->duration = duration;
    }

    void set_color_available(bool color){
      this->color_available = color;
    }

    long get_duration() const{
      return this->duration;
    }

    bool get_color_available() const{
      return this->color_available;
    }

    virtual void print() const = 0;
};

class book_t: public textual_doc_t{
    vector<char*> authors;// vecteur des autheurs pour pas besoin d'initialiser
    int nauthors;
    const char *publisher;
    long ISBN;
  public:
    book_t(){
      this->nauthors = 0;
      this->publisher = NULL;
      this->isbn = 0;
    };

    ~book_t(){};

    void print() const {

       printf("Book (\"%s\", (", get_name() ) ;
      for (int i = 0; i < this->nauthors; i++) {
        if (i == this->nauthors - 1) {
          printf("%s", this->authors[i]);
        }
        else{
          printf("%s, ", this->authors[i]);
        }
      }
      printf("), \"%s\", %d, %ld)",  this->publisher, get_year(), this->isbn);
    };

    void add_author(const char* author){
      this->authors.resize(this->nauthors+1);
      this->authors[this->nauthors] = author;
      this->nauthors = this->nauthors + 1;
    };


    void set_publisher(const char* publisher){
      this->publisher = publisher;
    };

    void set_isbn(long isbn){
      this->isbn = isbn;
    };
};

class library_t{
    char *name;
    vector<day_t> days;
    int ndays;
    vector<book_t> books;
    int nbooks;
    public:
        void create(){
            this->name=NULL;
            this->ndays=0;
            this->nbooks=0;

        };

        void add_day(day_t day){
            days.resize(this->ndays+1);
            this->days[this->ndays]=day;
            this->ndays=this->ndays+1;
        };

        void add_book(book_t book){
            books.resize(this->nbooks+1);
            this->books[this->nbooks]=book;
            this->nbooks=this->nbooks+1;
        };

        void print() const{
            printf(" (\"%s\"), (",this->name);
            for(int i=0;i<this->ndays;i++){
                switch(this->days[i]){
                    case monday:
                    printf("\"monday\"");
                    break;
                    case tuesday:
                    printf(",\"tuesday\"");
                    break;
                    case wednesday:
                    printf(",\"wednesday\"");
                    break;
                    case thursday:
                    printf(",\"thursday\"");
                    break;
                    case friday:
                    printf(",\"friday\"");
                    break;
                    case saturday:
                    printf(",\"saturday\"");
                    break;
                    case sunday:
                    printf(",\"sunday\"");
                    break;

                }
            }
            printf("),");
            for(int i=0;i<this->nbooks;i++){
                books[i].print();
            }
            printf("\n");
        };
        void set_name(char *name){
            this->name=name;
        }


};

int main(){
    library_t  Sciences_Library;
    book_t Cprog;
    Cprog.create();
    Cprog.add_author(const_cast<char*>("Bjarne Stroustrup"));
    Cprog.set_name(const_cast<char*>("The C++ Programming Language"));
    Cprog.set_year(2013);
    Cprog.set_publisher(const_cast<char*>("Addison-Wesley"));
    Cprog.set_ISBN(9780321563842);
    Sciences_Library.create();
    Sciences_Library.add_day(monday);
    Sciences_Library.add_day(tuesday);
    Sciences_Library.add_day(wednesday);
    Sciences_Library.add_day(thursday);
    Sciences_Library.add_book(Cprog);
    Sciences_Library.set_name(const_cast<char*>("Sciences Library"));
    Sciences_Library.print();





    return 0;
}
