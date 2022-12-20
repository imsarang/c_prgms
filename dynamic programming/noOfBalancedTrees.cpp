#define mod 1000000007
int balancedBTs(int n) {
    // Write your code here
    if(n<=1){
        return 1;
    }
    int x = balancedBTs(n-1);
    int y = balancedBTs(n-2);
    int tempx = int((long(x)*x)%mod);
    int tempy = int((long(x)*y*2)%mod);
    return (tempx + tempy)%mod;
}

// using dynamic programming
int balancedBTs_dynamic_programming(int n) {
    // Write your code here
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 3;
    for(int i=3;i<n+1;i++){
        ans[i] = (int((long(ans[i-1])*ans[i-1])%mod) + int((2*long(ans[i-1])*ans[i-2])%mod))%mod;
    }
    return ans[n];
}