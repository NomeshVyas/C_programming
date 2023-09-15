#include<stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 7 - Plus
    //         *
    //         * 
    //     * * * * *
    //         *
    //         *

    int i, j=0, n=7;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j==n/2 || i==n/2){
                printf(" *");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}