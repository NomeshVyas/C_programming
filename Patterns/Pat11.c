#include <stdio.h>

int main(){
    //// Pattern 11 - Floyd's Triangle.
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    
    int n, i, j, k=1;
    printf("Enter the rows you want: ");
    scanf("%d", &n);
    printf("\n");

    for(i=0; i<n; i++){
        for(j=0; j<=i; j++){
            printf(" %d ", k);
            k+=1;
        }
        printf("\n");
    }

    return 0;
}