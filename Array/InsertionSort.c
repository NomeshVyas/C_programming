#include<stdio.h>

void insertionSort(int arr[], int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertionSort(a, n);
    printf("\nSorted Array: \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);

    return 0;
}