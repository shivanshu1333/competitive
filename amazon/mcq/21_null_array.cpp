// Ok here
#include<stdio.h>
int main(){
    int i;
    char x[]="\0";
    if(printf("%s\n", x))
        printf("Ok here \n");
    else
        printf("Forget it\n");
}