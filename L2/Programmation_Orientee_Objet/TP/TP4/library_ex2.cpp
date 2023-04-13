#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;


enum day_t { monday, tuesday, wednesday, thursday, friday, saturday, sunday };

char days_char[7][15] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

class doc_t{

  const char* name;
  int year;

  public:
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
    void println(){
      this->print();
    };
};
///////////////////// definitions sub classes //////////////////////////////////
class audio_doc_t : public doc_t {
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

class textual_doc_t : public doc_t {
  virtual void print() const = 0;
};

class video_doc_t : public doc_t{
  int duration;
  bool color_available;

public:
  video_doc_t(){
    this->duration = 0;
    this->color_available = false;
  }

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
///////////////////// definitions objects //////////////////////////////////////
class audio_tape_t : public audio_doc_t{
public:
  void print() const {
     printf("Audio tape (\"%s\", %d, %d s \n)", get_name(), get_year(), get_duration() ) ;
  };
};

class audio_cd_t : public audio_doc_t{
public:
  void print() const {
     printf("Audio cd (\"%s\", %d, %d s\n)", get_name(), get_year(), get_duration() ) ;
  };
};

class book_t : public textual_doc_t{
  vector<const char*> authors;
  int nauthors;
  const char* publisher;
  long isbn;

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
      printf("), \"%s\", %d, %ld\n)",  this->publisher, get_year(), this->isbn);
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

class newspaper_t : public textual_doc_t{
  const char* publisher;
  long int issn;

  public:
    void print() const {
       printf("Newspaper (\"%s\", %d, %s, %8ld \n)", get_name(), get_year(), this->publisher, this->issn);
    };

    newspaper_t(){
      this->publisher = NULL;
      this->issn = 0;
    }



    void set_publisher(const char* publisher){
      this->publisher = publisher;
    };

    void set_issn(const long int issn){
      this->issn = issn;
    };
};

class video_tape_t : public video_doc_t{
  public:
    void print() const {
       printf("Video tape (\"%s\", %d, %ld s, color available : %i \n)", get_name(), get_year(), get_duration(), get_color_available()) ;
    };
};

class dvd_t : public video_doc_t{
public:
  void print() const {
     printf("DVD (\"%s\", %d, %ld s, color available : %i\n)", get_name(), get_year(), get_duration(), get_color_available()) ;
  };
};

class blu_ray_t : public video_doc_t{
public:
  void print() const {
     printf("Blu-ray (\"%s\", %d, %ld s, color available : %i\n)", get_name(), get_year(), get_duration(), get_color_available()) ;
  };
};

class audio_text_t : public audio_doc_t, public textual_doc_t{
public:
  void print() const {
     printf("Audio text (\"%s\", %d, %d s\n)", audio_doc_t::get_name(), audio_doc_t::get_year(), get_duration() ) ;
  };
};






int main() {

      //science
      book_t book1, book2, book3, book4;
      audio_tape_t audio_tape;
      audio_cd_t cd;
      newspaper_t newspaper;
      video_tape_t video_tape;
      dvd_t dvd;
      blu_ray_t blu_ray;
      audio_text_t audio_text;

  //Inituation book //
      book1.set_name("The C++ Programming Language");
      book1.add_author("Addison-Wesley");
      book1.set_publisher("McGraw-Hill");
      book1.set_year(2013);
      book1.set_isbn(9780321563842);

      book2.set_name("C++: The Complete Reference");
      book2.add_author("Herbert Schildt");
      book2.set_publisher("McGraw-Hill");
      book2.set_year(2003);
      book2.set_isbn(9780070532465);

      book3.set_name("Harry Potter and the Philosopher's Stone");
      book3.add_author("J. K. Rowling");
      book3.set_publisher("Bloomsbury");
      book3.set_year(1997);
      book3.set_isbn(9780747532699);

      book4.set_name("Harry Potter and the Chamber of Secrets");
      book4.add_author("J. K. Rowling");
      book4.set_publisher("Bloomsbury");
      book4.set_year(1998);
      book4.set_isbn(9780747538493);
  // Initiation audio
      audio_tape.set_name("Killers");
      audio_tape.set_year(1981);
      audio_tape.set_duration(2298);

      cd.set_name("The Book of Souls");
      cd.set_year(2015);
      cd.set_duration(5531);
  //initation newspaper
      newspaper.set_name("The Guardian");
      newspaper.set_year(1821);
      newspaper.set_publisher("Guardian Media Group");
      newspaper.set_issn(726591);
  //intitiation video
      video_tape.set_name("Aladdin");
      video_tape.set_year(1992);
      video_tape.set_duration(5400);
      video_tape.set_color_available(true);

      dvd.set_name("The Lion King");
      dvd.set_year(1994);
      dvd.set_duration(5280);
      dvd.set_color_available(true);

      blu_ray.set_name("Zootopia");
      blu_ray.set_year(2016);
      blu_ray.set_duration(6480);
      blu_ray.set_color_available(true);

      audio_text.audio_doc_t::set_name("Harry Potter and the Philosopher's Stone");
      audio_text.audio_doc_t::set_year(1997);
      audio_text.set_duration(18000);
  //println des différents éléments//
      book1.println();
      book2.println();
      book3.println();
      book4.println();
      audio_tape.println();
      cd.println();
      newspaper.println();
      video_tape.println();
      dvd.println();
      blu_ray.println();
      audio_text.audio_doc_t::println();






  return 0;
}
