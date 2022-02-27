// ci, 6  note a=97
#include<stdio.h>
int main(){
    int i;
    char a[5] = {97, 99, 101, 103, 105};
    for(i=0;i<5;i=i+2)
        printf("%c" ,a[++i]);
    printf(", %d", i);
}