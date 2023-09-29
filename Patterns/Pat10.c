#include <stdio.h>

int main(){
    //// Pattern 10 - Inverted full pyramid of *
    // * * * * * * * * *
    //   * * * * * * *
    //     * * * * *
    //       * * *
    //         *
    
    int n, i, j, space=0;
    printf("Enter the rows you want: ");
    scanf("%d", &n);
    printf("\n");

    for(i=n; i>=1; i--){
        for(space=0; space<n-i; space++)
            printf("   ");

        for(j=0; j<i*2-1; j++)
            printf(" * ");

        printf("\n");
    }

    return 0;
}