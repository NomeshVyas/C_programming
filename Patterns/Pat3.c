#include <stdio.h>
#include<stdlib.h>

int main(){

    ////// Pattern 3 - Half Pyramid of Alphabets
    // A
    // B B
    // C C C
    // D D D D
    
    int i, j;
    char alpha;
    printf("Enter the rows you want to print in the last row: ");
    scanf("%c", &alpha);

    for(i=0; i<=(alpha-'A'); i++){
        for(j=0; j<=i; j++){
            printf("%c ", ('A'+i));
        }
        printf("\n");
    }
    
    return 0;
}