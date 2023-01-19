#include <iostream>
#include "./allRecursionFunctions.h"
#include <vector>
#include <utility>

using namespace std;
int main()
{
    char input[1000];
    cin >> input;
    // cout << checkPalindrome(input);
    // vector<pair<int, int>> output;
    // TowerOfHanoi(3, 1, 3, 2, output);
    // for (int i = 0;i<output.size();i++)
    // {
    //     cout << "Source : " << output[i].first << " Destination : " << output[i].second << endl;
    // }
    removeX(input);
    cout<<input;
    return 0;
}