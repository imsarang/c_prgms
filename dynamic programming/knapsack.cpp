#include<bits/stdc++.h>
using namespace std;
// brute force method:

int knapsack(int *weight,int *values,int n,int maxWeight){
    // Base conditions
    if(n==0 || maxWeight <=0){
        return 0;
    }
    // Recursive calls

    // if weight[0] > maxWeight : leave that element ans go to next element in the array
    if(weight[0] > maxWeight){
        return knapsack(weight+1,values+1,n-1,maxWeight);
    }

    // including current weight
    int x = knapsack(weight+1,values+1,n-1,maxWeight-weight[0]) + values[0];

    // not including current weight
    int y = knapsack(weight+1,values+1,n-1,maxWeight);

    return max(x,y); 
}

// dynamic programming : most optimized solution
int knapsack_dp(int* weight, int* value, int n, int maxWeight) {
    int dp[maxWeight+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int w=maxWeight;w>=0;w--)
        {
            if(weight[i]>w)
                continue;
            dp[w]=max(dp[w],dp[w-weight[i]]+value[i]);
        }
    }
    return dp[maxWeight];
}
