#include<cmath>
#include<bits/stdc++.h>
using namespace std;

// Brute force recursion
int helperWays(int x ,int n,int curr_num,int curr_sum){

  int res = 0;
  int p = pow(curr_num, n);
  while (p + curr_sum < x) {
    res += helperWays(x, n, curr_num + 1, curr_sum + p);
    curr_num++;
    p = pow(curr_num, n);
  }
  if (p + curr_sum == x)
    res++;
  return res;
}
int getAllWays(int a, int b) {
	// Write your code here
	return helperWays(a,b,1,0); 
}