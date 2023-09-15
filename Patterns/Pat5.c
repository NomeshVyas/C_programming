#include<stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 4 - Inverted half pyramid of numbers
    // 1 2 3 4 5
    // 1 2 3 4 
    // 1 2 3
    // 1 2
    // 1
    
    int i, j, n;
    printf("Enter no. of rows you want: ");
    scanf("%d", &n);

    for(i=n; i>0; i--){
            for(j=1; j<=i; j++){
                printf("%d ", j);
            }
        printf("\n");
    }
    
    return 0;
}