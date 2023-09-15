#include<stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 8 - Sathiya
    //     *   * * *
    //     *   * 
    //     * * * * *
    //         *   *
    //     * * *   *

    int i, j, n=11;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==n/2 || j==n/2){
                printf(" *");
            }
            else if((j==0 && i<n/2) || (j==n-1 && i>n/2) || (i==0 && j>n/2) || (i==n-1 && j<n/2) || (i==n/4 && j==n/4) || (i==n/2+n/4 && j==n/2+n/4) || (i==n/4 && j==n/2+n/4) || (i==n/2+n/4 && j==n/4)) {
                printf(" ");
            }
            else {
                printf("  ");
            }
            if ((j==0 && i<n/2) || (j==n-1 && i>n/2) || (i==0 && j>n/2) || (i==n-1 && j<n/2) || (i==n/4 && j==n/4) || (i==n/2+n/4 && j==n/2+n/4) || (i==n/4 && j==n/2+n/4) || (i==n/2+n/4 && j==n/4)) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}