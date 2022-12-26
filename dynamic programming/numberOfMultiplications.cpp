#include <vector>
#include <bits/stdc++.h>
using namespace std;

int helperMemo(vector<vector<int>> &dp, int *arr, int s, int e)
{
    // Base condition
    if (e - s == 1)
        return 0;

    // check memory for value
    if (dp[s][e])
        return dp[s][e];

    // initialize element with max value
    int ans = INT_MAX;
    for (int i = s + 1; i < e; i++)
    {
        int temp = helperMemo(dp, arr, s, i) + helperMemo(dp, arr, i, e) + arr[s] * arr[e] * arr[i];
        ans = min(temp, ans);
    }
    dp[s][e] = ans;
    return ans;
}
int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    return helperMemo(dp, arr, 0, n);
}