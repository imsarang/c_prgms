#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// always find minimum element in the array
// swapping of elements is done

void selectionSort(int input[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        // find min element
        int min = input[i];
        int pos=i;
        for (int j = 1; j < n; j++)
        {
            if (input[j] < min)
            {
                min = input[j];
                pos = j;
                // cout<<"Pos : "<<pos<<endl;
            }
        }

        // swapping of elements
        int temp = input[i];
        input[i] = input[pos];
        input[pos] = temp;
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
    selectionSort(input, n);
    for(int i = 0;i<n;i++){
        cout<<input[i]<<" ";
    }
}