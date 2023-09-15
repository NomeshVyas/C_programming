#include<stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 6 - Full Pyramid of *
    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *

    int i, j=0, space, n;
    printf("Enter no. of rows you want: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++, j=0){
        for(space=1; space<=n-i; space++){
            printf("  ");
        }
        while(j != 2*i-1){
            printf("* ");
            j += 1;
        }
        printf("\n");
    }
    
    return 0;
}