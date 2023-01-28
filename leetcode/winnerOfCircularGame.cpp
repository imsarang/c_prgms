int helper(int n,int k){
    if(n==1) return 0;
    return ((k+1)%n + helper(n-1,k))%n;
}
int findTheWinner(int n, int k) {
    // Write your code here
    return helper(n,k-1) + 1;
}   