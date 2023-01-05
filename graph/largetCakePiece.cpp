#include <iostream>
#include<vector>

using namespace std;

int max(int x,int y){
    if(x>y) return x;
    else return y;
}

void dfs(vector<vector<int>> &cake,int n,int i,int j,int &count){
    cake[i][j] = 0;
    count++;

    // up
    if(i-1>=0 && cake[i-1][j]==1) dfs(cake,n,i-1,j,count);

    // left
    if(j-1>=0 && cake[i][j-1] == 1) dfs(cake,n,i,j-1,count);

    // down
    if(i+1<n && cake[i+1][j] == 1) dfs(cake,n,i+1,j,count);

    // right
    if(j+1<n && cake[i][j+1] == 1) dfs(cake,n,i,j+1,count);

}
int getBiggestPieceSize(vector<vector<int>>&cake,int n){
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(cake[i][j] == 1){
                int temp = 0;
                dfs(cake,n,i,j,temp);
                ans = max(ans,temp);
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}