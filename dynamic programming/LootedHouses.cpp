#include <bits/stdc++.h>
using namespace std;
// Brute force recursion
int houseLooted(int *arr,int n){
    if(n<=0) return 0;
    int sum1 = houseLooted(arr+1,n-1);
    int sum2 = houseLooted(arr+2,n-2);

    return max(sum1,sum2+arr[0]);
}

// using dynamic programming
int dpLooted(int *arr,int n,int *dp){
	dp[0] = arr[0];
	dp[1] = max(arr[0],arr[1]);

	// dp iteration from 2
	for(int i = 2;i<=n;i++){
		dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
	}
	return dp[n-1];
}
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *dp = new int[n+1];
    return dpLooted(arr,n,dp);
}