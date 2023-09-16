#include<stdio.h>
#include<stdlib.h>

int main(){
    ////// Pattern 9 - Inverted half pyramid of numbers
    //         1
    //       2 3 2
    //     3 4 5 4 3
    //   4 5 6 7 6 5 4
    // 5 6 7 8 9 8 7 6 5

    int i, j, k, n, space;

    printf("\nEnter the number of lines you want to print: ");
    scanf("%d", &n);
    printf("\n");
    for(i=1; i<=n; i++){
        for(space=1; space<=n-i; space++){
            printf("   ");
        }
        j=0;
        k=i;
        while(j < i*2-1){
            if(j==i-1){
                printf(" %d ", k);
            }else if(j<i) {
                printf(" %d ", k);
                k+=1;
            } else {
                k-=1;
                printf(" %d ", k);
            }
                j+=1;
        }
        printf("\n");
    }

    return 0;
}