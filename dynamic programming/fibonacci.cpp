/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// memoization : top-down : generally recursive
// dp_main : dynamic programming : bottom-up generally iterative
int fibo_memoization(int n,int *ans){
    if(n<=1){
        return n;
    }
    
    // check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    
    int a = fibo_memoization(n-1,ans);
    int b = fibo_memoization(n-2,ans);
    
    // save the output in the ans array for future use
    ans[n] = a+b;
    return ans[n];
}

int fibo_dp_main(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<=n;i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int fibo(int n){
    int *ans = new int[n+1];
    // initialize array with -1 so that garbage value is not there in the array
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return fibo_memoization(n,ans);
}
int main()
{
    cout<<"Fibonacci using dp"<<endl;
    cout<<fibo(6);
    return 0;
}
