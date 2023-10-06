#include<stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
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

    quickSort(a, 0, n-1);
    printf("\nSorted Array: \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);

    return 0;
}