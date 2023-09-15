#include <stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 1 - Half Pyramid of Numbers
    //// 1
    //// 1 2
    //// 1 2 3
    //// 1 2 3 4
    //// 1 2 3 4 5
    
    int n, i, j;
    printf("Enter the rows you want: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            printf("%d ", i);
        }
        printf("\n");
    }    
    return 0;
}