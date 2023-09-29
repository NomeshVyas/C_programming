#include<stdio.h>

void swapping(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min_idx;

    for(i=0; i<n-1; i++){
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[min_idx]>arr[j])
                min_idx = j;
        }
        if(min_idx != i)
            swapping(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int i, n, a[100];
    printf("Length of Array: ");
    scanf("%d", &n);

    printf("\nEnter the elements of Array: \n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    printf("\nGiven Array: \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);

    selectionSort(a, n);
    printf("\nSorted Array: \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);

    return 0;
}