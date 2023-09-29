#include<stdio.h>

void swapp(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    int i, j, swapped;

    for(i=0; i<n-1; i++){
        swapped=0;
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
                swapp(&arr[j], &arr[j+1]);
                swapped=1;
        }
        if(swapped==0)
            break;
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

    bubbleSort(a, n);
    printf("\nSorted Array: \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);

    return 0;
}