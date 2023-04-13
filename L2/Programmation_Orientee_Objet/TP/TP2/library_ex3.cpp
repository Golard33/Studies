#include <cstdio> // for printf
typedef enum {
    monday, tuesday, wednesday, thursday, friday,saturday,sunday
}d_t;

//char jours[7][100]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
typedef struct {
    char name[100];
    char authors[10][100];
    int nauthors;
    char publisher[100];
    int year;
    long int ISBN;
    void print(){
        printf("((\"%s\", (",this->name);
        for (int i=0;i<nauthors;i++){
            printf("\"%s\"",this->authors[i]);
        }
        printf(") (\"%s\", %d, %ld)",this->publisher,this->year,this->ISBN);

    }


}b_t;

typedef struct {
    char name[100];
    d_t days[7];
    int ndays;
    b_t books[100];
    int nbooks;
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
    }

}l_t;

int main(){
    l_t  Sciences_Library ={"Sciences Library",{monday,tuesday,wednesday,thursday},4,{{"The C++ Programming Language",{"Bjarne Stroustrup"},1,"Addison-Wesley",2013,9780321563842},{"C++: The Complete Reference",{"Herbert Schildt"},1,"McGraw-Hill",2003, 9780070532465}},2 };
    Sciences_Library.print();




    return 0;
}
