#include <iostream>
#include <vector>
#include <utility>

#include "./allRecursionFunctions.h"
#include "./allSortingFuctions.h"

using namespace std;
int main()
{
    //char input[1000];
    //cin >> input;
    // cout << checkPalindrome(input);
    // vector<pair<int, int>> output;
    // TowerOfHanoi(3, 1, 3, 2, output);
    // for (int i = 0;i<output.size();i++)
    // {
    //     cout << "Source : " << output[i].first << " Destination : " << output[i].second << endl;
    // }
    //removeX(input);
    // cout<<input;
    int input[] = {9,3,7,2,1,5,6};
    // mergeSort(input,7);
    quickSort(input,7);
    for(auto i : input){
        cout<<i<<" ";
    }
    return 0;
}