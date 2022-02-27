//infinite
#include<stdio.h>
int main();
void show(){
    printf("\n My name is Andy too");
    main();
}
int main(){
    printf("My name is Mike");
    show();
}