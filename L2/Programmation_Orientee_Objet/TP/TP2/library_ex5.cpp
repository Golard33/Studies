#include <cstdio> // for printf
#include <vector> // for vector
using namespace std; //for vector
enum day_t{
    monday, tuesday, wednesday, thursday, friday,saturday,sunday
};

class book_t{
    char *name;
    vector<char*> authors;
    int nauthors;
    char *publisher;
    int year;
    long int ISBN;
    public:
        void print(){
            printf("((\"%s\"",this->name);
            for (int i=0;i<nauthors;i++){
                printf("(\"%s\")",authors[i]);
            }
            printf(",  (\"%s\", %d, %ld)",this->publisher,this->year,this->ISBN);

        }
        void create(){
            this->name=NULL;

            this->nauthors=0;
            this->year=0;
            this->ISBN=0.0;
        };

        void add_author(char *author){
            authors.resize(nauthors+1);
            this->authors[this->nauthors]=author;
            this->nauthors=this->nauthors+1;
        };
        void set_name(char *name){
            this->name=name;
        };
        void set_publisher(char* publisher){
            this->publisher=publisher;
        };
        void set_year(int year){
            this->year=year;
        };
        void set_ISBN(long int ISBN){
            this->ISBN=ISBN;
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

        void print(){
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
