#include <stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 2 - Half Pyramid of *
    //// *
    //// * *
    //// * * *
    //// * * * *
    
    int n, i, j;
    printf("Enter the rows you want: ");
    scanf("%d", &n);
    printf("\n");

    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}