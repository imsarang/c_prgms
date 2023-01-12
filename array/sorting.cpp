#include <iostream>
#include <bits/stdc++.h>
#include "./allSortingAlgo.h"

using namespace std;
void printArray(int input[],int n){
     for(int i = 0;i<n;i++){
        cout<<input[i]<<" ";
    }
}

int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    // selectionSort(input, n);
    bubbleSort(input,n);
    printArray(input,n);
}