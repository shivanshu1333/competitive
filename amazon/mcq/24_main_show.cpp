// 1 1 1
// 1 1 2
#include<stdio.h>
void show();

int main(){
    show();
    show();
}

void show(){
    int i=0;
    register int j=0;
    static int k;
    i++;
    j++;
    k++;
    printf("\n%d %d %d", i, j, k);
}