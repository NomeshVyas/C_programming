#include<stdio.h>

int max(int a, int b){
    return (a>b) ? a : b;
}

int knapsack(int c, int wt[], int pt[], int n){
    if(c==0 || n==0)
        return 0;
    if(wt[n-1] > c)
        return knapsack(c, wt, pt, n-1);
    return max(pt[n-1] + knapsack(c-wt[n-1], wt, pt, n-1), knapsack(c, wt, pt, n-1));
}

int main(){
    int weight[] = {1, 3, 4, 6};
    int profit[] = {20, 30, 10, 50};
    int capacity = 10;
    int n = sizeof(profit)/sizeof(profit[0]); 

    printf("0/1 Knapsack solution of given problem : %d", knapsack(capacity, weight, profit, n));
}