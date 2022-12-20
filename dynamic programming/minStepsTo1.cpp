#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// Complexity : O(2^n)
int countMinStepsToOne(int n)
{
    // Write your code here
    if (n <= 1)
        return 0;
    int x = countMinStepsToOne(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = countMinStepsToOne(n / 2);
    if (n % 3 == 0)
        z = countMinStepsToOne(n / 3);
    int ans = min(x, min(y, z)) + 1;
    return ans;
}

// using dynamic programming
// compexity : O(n)
int countStepsToOne(int n)
{
	//Write your code here
        int a[n + 1];

        a[1] = 0;
        a[2] = a[3] = 1;
        int b, c;
        for (int i = 4; i < n + 1; i++) {
          b = c = n;

          if (i % 2 == 0)
            b = a[i / 2];
          if (i % 3 == 0)
            c = a[i / 3];

          a[i] = 1 + min(a[i - 1], min(b, c));
        }
        return a[n];
}

// memoization
// complexity : O(n)
int minStepsHelper(int n,int *ans){
  if(n<=1)return 0;
  if(ans[n]!=-1){
    return ans[n];
  }

  // calculate output
  int x = minStepsHelper(n-1,ans);
  int y = INT16_MAX,z=INT16_MAX;
  if(n%2==0){
    y = minStepsHelper(n/2,ans);
  }
  if(n%3==0){
    z = minStepsHelper(n/3,ans);
  }

  int output = min(x,min(y,z))+1;

  // save output
  ans[n] = output;

  return output;
}
int countStepsTo1Memo(int n){
  int *ans = new int[n+1];
  for(int i = 0;i<n+1;i++){
    ans[i] = -1;
  }
  return minStepsHelper(n,ans);
}