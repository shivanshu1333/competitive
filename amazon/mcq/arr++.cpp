// arr cannot be incremented
#include<stdio.h>
int main(){
    char arr[10]="rectangle"; //Line3
    int i;
    for(i=0;i<=7;i++)
        printf("%d", arr[i]);
    arr++;
}