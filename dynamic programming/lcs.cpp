#include<bits/stdc++.h>
using namespace std;
// brute force recursion method
// time complexity : exponential order: O(2^n)
int lcs(string s,string t){
    // base condition
    if(s.size()==0 || t.size()==0) return 0;

    // recursive calls
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1),t);
        int b = lcs(s,t.substr(1));
        int c = lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }
}

// Memoization
int lcs_mem(string s,string t,int **output){
    // Base condition
    if(s.size()==0 || t.size()==0) return 0;

    // Check if already encountered
    int m = s.size();
    int n = t.size();

    if(output[m][n]!=-1) return output[m][n];

    // Recursion calls
    int ans;
    if(s[0]==t[0]){
        ans = 1+ lcs_mem(s.substr(1),t.substr(1),output);
    }
    else{
        int a = lcs_mem(s.substr(1),t,output);
        int b = lcs_mem(s,t.substr(1),output);
        int c = lcs_mem(s.substr(1),t.substr(1),output);
        ans = max(a,max(b,c));
    }

    // Save Calculation
    output[m][n] = ans;

    // Return answer
    return ans;
}
int lcs_mem(string s,string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j] = -1;
        }
    }

    return lcs_mem(s,t,output);
}

// dynamic Programming