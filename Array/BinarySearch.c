#include<stdio.h>
//// Binary Search through Iterative method

//// Binary Search only works when Array is sorted.
int binarySearch(int arr[], int x, int low, int high);

int main() {
    int i, n, el, index, a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(a)/sizeof(a[0]);
    
    for(i=0; i<n; i++)
        printf("%d  ", a[i]);
    
    printf("\nEnter the element you want to index of: ");
    scanf("%d", &el);

    index = binarySearch(a, el, 0, n-1);
    if(index==-1)
        printf("\nElement not found");
    else
        printf("\nIndex of element %d is: %d", el, index);

    return 0;
}

int binarySearch(int arr[], int x, int low, int high) {
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid]<x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}