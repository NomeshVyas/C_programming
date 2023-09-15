#include <stdio.h>
#include<stdlib.h>

int main(){
    ////// Pattern 4 - Inverted half pyramid of *
    // * * * * *
    // * * * *
    // * * * 
    // * *
    // *

    int i, j, n;
    printf("Enter no. of rows you want: ");
    scanf("%d", &n);

    for(i=n; i>0; i--){
        for(j=i; j>0; j--){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}