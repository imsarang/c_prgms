#include <iostream>
#include <vector>
#include <utility>

#include "./allRecursionFunctions.h"
#include "./allSortingFuctions.h"

using namespace std;

// ALL printing functions here

// Print keypad problem
void keypadHelper(int num, string output, string options[10])
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }

    int digit = num % 10;
    // taking one character at a time inside a for loop : number of iterations = size of the options[digit] string
    for (int i = 0; i < options[digit].length(); i++)
    {
        keypadHelper(num / 10, options[digit][i] + output, options);
    }
    return;
}
void printKeypad(int num)
{
    string options[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keypadHelper(num, "", options);
}

// Print subsets problem
void printSubsetHelper(int input[], int n, int output[], int outputSize)
{

    // Base Condition
    if (n == 0)
    {
        for (int i = 0; i < outputSize; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive Calls
    printSubsetHelper(input + 1, n - 1, output, outputSize);

    int newOutput[20] = {};
    for (int i = 0; i < outputSize; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[outputSize] = input[0];
    printSubsetHelper(input + 1, n - 1, newOutput, outputSize + 1);
}

void printSubsets(int input[], int n)
{
    int ans[20] = {};
    printSubsetHelper(input, n, ans, 0);
}

// Print permutations
void permutationHelper(string input, string output)
{

    // Base Condition
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    // Recursion call
    for (int i = 0; i < output.length(); i++)
    {
        permutationHelper(input.substr(1), output.substr(0, i) + input[0] + output.substr(i));
    }
}

void permutationPrint(string input)
{
    // string output="";
    permutationHelper(input, "");
}

int main()
{
    /*char input[1000];
    cin >> input;
    cout << checkPalindrome(input);
    vector<pair<int, int>> output;
    TowerOfHanoi(3, 1, 3, 2, output);
    for (int i = 0; i < output.size(); i++)
    {
        cout << "Source : " << output[i].first << " Destination : " << output[i].second << endl;
    }
    removeX(input);
    cout << input;*/ 

    /*int input[] = {9,3,7,2,1,5,6};
    mergeSort(input,7);
    quickSort(input,7);
    for(auto i : input){
        cout<<i<<" ";
    }*/

    /*string input = "abc";
    string *output = new string[1000];
    int outputSize = stringSubSeq(input, output);
    int outputSize = keypad(23, output);
    cout << outputSize;
    for (int i = 0; i < outputSize; i++)
    {
        cout << output[i] << endl;
    }*/

    /* printKeypad(23);*/

    /*int outputSubset[1000][20];
    int inputSet[3] = {15, 12, 20};
    int subsetOutput = subsets(inputSet, 3, outputSubset);
    for (int i = 0; i < subsetOutput; i++)
    {
        for (int j = 1; j <= outputSubset[i][0]; j++)
        {
            cout << outputSubset[i][j] << " ";
        }
        cout << endl;
    }*/

    /*printSubsets(inputSet,3);*/

    /*string output[10000];
    int size = permutations("abcd",output);
    for(int i = 0;i<size;i++){
        cout<<output[i]<<endl;
    }*/

    int input[9] = {5,12,3,17,1,18,15,3,17},output[1000][50];
    int size = getSubsetsK(input,9,output,6);
    cout<<size;
    for(int i = 0;i<size;i++){
        for(int j = 1;j<output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}