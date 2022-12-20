/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool isPossible(int n,int row,int col){
    
    // same column
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    
    // for upper left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1)
        return false;
    }
    
    // for upper right diagonal
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]==1)
        return false;
    }
    return true;
}
void nQueenHelper(int n,int row){
    if(row==n){
        // some solution reached
        // print the board matrix
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    // Place at all possible positions and move to smaller problems
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j] = 1;
            nQueenHelper(n,row+1);
            // for backtracking, the case when the solution wont hold for the previous step
            board[row][j] = 0;
        }
    }
    return;
}
void placeNQueens(int n){
    memset(board,0,11*11*sizeof(int));
    nQueenHelper(n,0);
}

int main()
{
    placeNQueens(4);

    return 0;
}
