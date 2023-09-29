#include <stdio.h>

int main(){
    //// Pattern 12 - Pascal's Triangle
    //            1
    //          1   1
    //        1   2   1
    //      1   3   3   1
    //    1  4    6   4   1
    //  1  5   10   10  5   1

    int i, j, n, space, c=1;
    printf("How many lines you want to print: ");
    scanf("%d", &n);

    for(i=0;i<n; i++){
        for(space=0; space<n-i; space++){
            printf("  ");
        }
        for(j=0; j<=i; j++){
            if(j==0)
                c=1;
            else
                c=c*(i-j+1)/j;
            printf("%4d", c);
        }
        printf("\n");
    }

    return 0;
}