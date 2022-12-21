#include<bits/stdc++.h>
using namespace std;

// bruteforce recursion method:
// time complexity : O(3^n)
int editDistance(string s1, string s2) {
	// Write your code here
	
	// base condition
	if(s1.size()==0 || s2.size()==0 ) return max(s1.size(),s2.size());

	// recursive calls
	if(s1[0] == s2[0]){
		return editDistance(s1.substr(1),s2.substr(1));
	}
	else{
		// insert
		int a = editDistance(s1.substr(1),s2) + 1;
		// delete
		int b = editDistance(s1.substr(1),s2.substr(1))+1;
		//replace 
		int c = editDistance(s1,s2.substr(1))+1;
		return min(a,min(b,c));
	}
}

// memoization
int editDistance_mem(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();
	
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	if(s[0] == t[0]) {
		ans = editDistance_mem(s.substr(1), t.substr(1), output);
	}
	else {
		// Insert
		int x = editDistance_mem(s.substr(1), t, output) + 1;
		// Delete
		int y = editDistance_mem(s, t.substr(1), output) + 1;
		// Replace
		int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

		ans =  min(x, min(y, z));
	}

	// Save the ans
	output[m][n] = ans;

	// Return the ans
	return ans;
}
int editDistance(string s, string t){

    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        ans[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            ans[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, ans);
}

// Dynamic Programming
int editDistance_DP(string s,string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n];
    }

    // Fill first row
    for(int i=0;i<=n;i++){
        output[0][i] = i;
    }

    // Fill first column
    for(int i=0;i<=m;i++){
        output[i][0] = i;
    }

    for(int i = 1;i<=m;i++){
        for(int j=1;j<=n;j++){
            // Check for character matching
            if(s[m-i] == t[n-j]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                int a = output[i-1][j];
                int b = output[i-1][j-1];
                int c = output[i][j-1];
                output[i][j] = min(a,min(b,c))+1;
            }
        }
    }
}