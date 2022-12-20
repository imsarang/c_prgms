#include <bits/stdc++.h>
using namespace std;

// using brute force recursion
// time complexity : 
int minCostPath(int **input, int m, int n, int i, int j) {
  // Base cases
  if (i == m - 1 && j == n - 1)
    return input[i][j];
  if (i >= m || j >= n)
    return INT_MAX;
  // Recursive calls
  int x = minCostPath(input, m, n, i, j+1);
  int y = minCostPath(input, m, n, i + 1, j + 1);
  int z = minCostPath(input, m, n, i+1, j);

  // Small calculation
  int ans = min(x, min(y, z))+input[i][j];
  return ans;
}
int minCostPath(int **input, int m, int n) {
  return minCostPath(input, m, n, 0, 0);
}

// memoization (handling repeated values coming in brute force recursion)
int minCostPathMemo(int **input,int m,int n,int i,int j,int **output){
    // Base conditions
    if(i==m-1&&j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n) return INT_MAX;

    // Check if element already encountered
    if(output[i][j]!=-1) return output[i][j];

    // recursive calls
    int x = minCostPathMemo(input,m,n,i,j+1,output);
    int y = minCostPathMemo(input,m,n,i+1,j+1,output);
    int z = minCostPathMemo(input,m,n,i+1,j,output);
    
    // small calculation
    int ans = min(x,min(y,z))+input[i][j];
    output[i][j] = ans;
    return output[i][j];
}

int minCostPathMemo(int **input,int m,int n){
    int **output = new int*[max(m,n)];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            output[i][j] = -1;
        }
    }
    return minCostPathMemo(input,m,n,0,0,output);
}

// using dynamic programming
// time complexity : O(m*n)
// space complexity : O(m*n) since new 2D array is created (output array in our code)
int minCostPath_DP(int **input,int m,int n){
    int **output = new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
    }

    // fill the last cell i.e destination
    output[m-1][n-1] = input[m-1][n-1];

    // fill the last row(right to left)
    for(int j = n-2;j>=0;j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }

    // fill the last column(bottom to top)
    for(int i=m-2;i>=0;i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    // fill remaining cells
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j] = min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]));
        }
    }

    return output[0][0];
}