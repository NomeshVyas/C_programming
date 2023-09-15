#include<stdio.h>
#include<conio.h>

int main() {
    int i, j, a[2][2], b[2][2];
    printf("Enter elements of Matrix you want to transpose: \n");

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("row-%d, col-%d element: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nGiven Matrix: \n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of given Matrix: \n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            b[i][j] = a[j][i];
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}