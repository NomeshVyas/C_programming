#include<stdio.h>
int main(){
    int i, j, a[2][2], b[2][2], c[2][2];
    printf("\nEnter elements of 1st Matrix:\n");

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("Enter row-%d, column-%d element: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of 2nd Matrix:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("Enter row-%d, column-%d element: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n1st Matrix:\n");
    for(i=0; i<2; i++){
        for(j=0;j<2;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n\n");
    }

    printf("2nd Matrix:\n");
    for(i=0; i<2; i++){
        for(j=0;j<2;j++){
            printf("%d\t", b[i][j]);
        }
        printf("\n\n");
    }

    printf("Sum of given Matrix: \n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            c[i][j] = a[i][j] + b[i][j];
            printf("%d\t", c[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}