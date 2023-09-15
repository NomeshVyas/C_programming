#include<stdio.h>

int main() {
    int i, p, n=10, a[10];
    printf("Enter the values of Array (length=10): ");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("\nArray before deletion: \n\t {  ");
    for(i=0; i<n; i++)
        printf("%d  ", a[i]);
    printf("}");

    printf("\nEnter the index of element you want to delete: ");
    scanf("%d", &p);

    for(i=p; i<n; i++)
        a[i]=a[i+1];
    
     printf("\nArray after deletion: \n\t {  ");
    for(i=0; i<n-1; i++)
        printf("%d  ", a[i]);
    printf("}");

    return 0;
}