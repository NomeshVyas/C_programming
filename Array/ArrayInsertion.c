////// Insertion in Array

#include<stdio.h>

int main() {
    int i, n, v, a[10];
    printf("Enter the values of Array (length=9): ");
    for(i=0; i<9; i++)
        scanf("%d", &a[i]);

    printf("Array before insertion: \n\t {  ");
    for(i=0; i<9; i++)
        printf("%d  ", a[i]);
    printf("}");

    printf("\nEnter the element's value to be inserted: ");
    scanf("%d", &v);
    printf("Enter the element's index to be inserted: ");
    scanf("%d", &n);

    for(i=8; i>=n; i--){
        a[i+1]=a[i];
    }
    a[n]=v;

    printf("Array after insertion: \n\t {  ");
    for(i=0; i<10; i++)
        printf("%d  ", a[i]);
    printf("}");

    return 0;
}