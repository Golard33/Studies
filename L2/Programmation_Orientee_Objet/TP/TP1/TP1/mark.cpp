#include <cstdio> // for printf
int main(){
    int mark=-1;
    while((mark<0) or (mark>20)){
        printf("mark:");
        scanf("%d",&mark);
        while(getchar() != '\n');

    }
    if(mark<10){
        printf("failing\n");
    }
    else{
          if(mark<12){
            printf("satisfactory\n");
          }
          else{
                if(mark<16){
                  printf("good\n");
                }
                else{
                  printf("excellent\n");
                }
              }
            }
          


    return 0;
}
