#include<bits/stdc++.h>
#include<vector>
#include<utility>

void mySwap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//***************** MERGE SORT ***********************//
// continuously divide the array in two parts from mid and sort the array using the two subparts
// Time Complexity :O(N(log N))
// Auxiliary Space = O(n)
// not In place algo , since it uses extra space to sort the given array
// Stable Algorithm

void merge(int input[],int start,int rear,int mid){
    int n1 = mid-start+1;
    int n2 = rear-mid;
    int L[n1],R[n2];
    int i,j,k;
    
    // Copy the array in two arrays L and R
    for(i=0;i<n1;i++){
        L[i] = input[start+i];
    }
    for(j=0;j<n2;j++){
        R[j] = input[mid+j+1];
    }

    i=0;j=0;k=0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            input[k] = L[i];
            i++;k++;
        }
        else{
            input[k] = R[j];
            j++;k++;
        }
    }

    // Copy the rest of elements if left
    while(i<n1){
        input[k] = L[i];
        i++;k++;
    }
    while(i<n2){
        input[k] = R[j];
        j++;k++;
    }

}

void mergeSort(int input[],int size){
    int l = 0;
    int r = size-1;
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(input+mid+1,r-mid);
        mergeSort(input,mid+1);
        merge(input,l,r,mid);
    }
}

// ********************* QUICK SORT **************************//
// continuously select the pivot of the array and place the elements such that all the elements less than the pivot element lie to the left of pivot and elements greater than pivot element lie to the right of the pivot
// Time Complexity : O(N(log N))
// Auxiliary/Space Complexity : O(log N) 
// In-place algo
// Stable Algorithm
// returns the pivot
int partition(int input[],int start,int end){
    int count=0,i,j;
    int x = input[start];
    for(i=start;i<=end;i++){
        if(x>input[i]) count++;
    }
    int pivot = start+count;
    
    // swap pivot with the first element of the array
    mySwap(&input[start],&input[pivot]);

    i = start;j=end;
    while(i<pivot && j>pivot){
        if(input[i] < input[pivot]) i++;
        else if (input[j] > input[pivot]) j--;
        else mySwap(&input[i],&input[j]);
    }
    return pivot;
}

void quickSortHelper(int input[],int start,int end){
    if(start>=end) return;
    int c = partition(input,start,end);
    quickSortHelper(input,start,c-1);
    quickSortHelper(input,c+1,end);

}
void quickSort(int input[],int size){
    quickSortHelper(input,0,size-1);
}