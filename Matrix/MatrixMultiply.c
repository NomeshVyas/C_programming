#include<stdio.h>

int main() {
    int i, j, k, sum=0, a[2][2], b[2][2], c[2][2];

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

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            c[i][j]=0;
            for(k=0; k<2; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    printf("Multiplied Matrix:\n");
    for(i=0; i<2; i++){
        for(j=0;j<2;j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}