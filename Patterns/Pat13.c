#include <stdio.h>

int main(){
    ////// Pattern 13 - Diamond of *
    //             * 
    //          *  *  *
    //       *  *  *  *  * 
    //    *  *  *  *  *  *  *
    // *  *  *  *  *  *  *  *  *
    //    *  *  *  *  *  *  *
    //       *  *  *  *  * 
    //          *  *  *
    //             * 

    int i, j, space, n=7;

    for(i=1; i<=n; i++){
        for(space=0; space<=n-i; space++){
            printf("   ");
        }
        for(j=1; j<=2*i-1; j++){
            printf(" * ");
        }

        printf("\n");
    }


    return 0;
}