#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define N 9

bool isSafeRow(int grid[N][N],int row,int num){
    
    for(int i=0;i<N;i++){
        if(grid[row][i]==num){
            return false;
        }
    }
    return true;
}

bool isSafeColumn(int grid[N][N],int col,int num){
    for(int i=0;i<N;i++){
        if(grid[i][col]==num){
            return false;
        }
    }
    return true;
}

bool isSafeMatrix(int grid[N][N],int row,int col,int num){
    int rowFactor = row-(row%3);
    int columnFactor = col-(col%3);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(grid[i+rowFactor][j+columnFactor]==num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[N][N],int row,int col,int num){
    if(isSafeRow(grid,row,num) && isSafeColumn(grid,col,num) && isSafeMatrix(grid,row,col,num)){
        return true;
    }
    return false;
}

bool isEmptyPlace(int grid[N][N], int &row,int &col){
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                row = i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool solveSudoku(int grid[N][N]){
    int row,col;
    if(!isEmptyPlace(grid,row,col)){
        return true;
    }

    for(int i = 0;i<N;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
}
int main(){
    
    // write your code here
    int grid[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }

    if(solveSudoku(grid)) cout<<"true";
    else cout<<"false";
    // cout<<result;
    // for(int i=0;i<N;i++){
    //     for(int j=0;i<N;j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}