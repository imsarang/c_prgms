#include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;
// two main cases: when the element is counted and when the element is not counted
// if element is counted : then reduce k value by that element 
// if element is skipped : recursivly call the function w/o changing k value
int countSubsets(int arr[],int n,int index,int k,int count){
   if(index==n){
       if(k==0)count++;return count;
   }
   count = countSubsets(arr,n,index+1,k-arr[index],count);
   count = countSubsets(arr,n,index+1,k,count);
   return count;
}
int main(){
    
    // write your code here
   int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int k;
        cin>>k;
        int arr[size];
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        
        cout <<countSubsets(arr,size,0,k,0)<<endl;
    }
    return 0;
}