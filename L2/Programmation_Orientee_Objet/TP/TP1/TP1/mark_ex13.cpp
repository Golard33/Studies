#include <cstdio> // for printf
int main(){
    int mark=-1;
    do{
        printf("mark:");
        scanf("%d",&mark);
        while(getchar() != '\n');

    }while((mark<0) || (mark>20));
    if(mark<10){
        printf("failing\n");
    }
    if((mark>=10) && (mark<12)){
        printf("satisfactory\n");
    }
    if((mark>=12) && (mark<16)){
        printf("good\n");
    }
    if(mark>=16){
        printf("excellent\n");
    }
          


    return 0;
}
