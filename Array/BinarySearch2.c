#include<stdio.h>
//// Binary Search through Recursive method

//// Binary Search only works when Array is sorted.

int binarySearch(int arr[], int el, int low, int high){
    if(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid]==el)
            return mid;
        else if(arr[mid]<el)
            return binarySearch(arr, el, mid+1, high);
        else
            return binarySearch(arr, el, low, mid-1);
    }
    return -1;
}

int main(){
    int i, n, el, index, a[]={10,20,30,40,50};
    n=sizeof(a)/sizeof(a[0]);
    printf("The Array: \n");

    for(i=0; i<n; i++){
        printf("%d\t", a[i]);
    }

    printf("\nEmter the element which index you want: ");
    scanf("%d", &el);

    index = binarySearch(a, el, 0, n-1);
    if(index==-1)
        printf("not found");
    else
        printf("index of %d is: %d", el, index);
    return 0;
}