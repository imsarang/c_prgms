#include <string.h>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

bool checkPalindrome(char input[])
{
    int n = strlen(input) - 1;
    // base condition
    if (input[0] != input[n])
        return false;

    // recursive call
    input[n] = '\0';
    bool ans = checkPalindrome(input + 1);
    if (n == 0 || n == 1)
        return true;
    else
        ans;
}

// & used in 5th parameter for output as it has to be called by its address for inserting elements in it
void TowerOfHanoi(int n, int src, int dest, int aux, vector<pair<int, int>> &output)
{

    if (n != 0)
    {
        // first disk goes from src to aux
        TowerOfHanoi(n - 1, src, aux, dest, output);

        // push the src and dest to output vector
        output.push_back(make_pair(src, dest));

        // disk moves from aux to dest
        TowerOfHanoi(n - 1, aux, dest, src, output);
    }
}

// remove all x charaters in a character array
void removeX(char input[])
{
    if (input[0] == '\n')
        return;

    if (input[0] == 'x')
    {
        for (int i = 0; input[i]; i++)
        {
            input[i] = input[i + 1];
        }
        return removeX(input);
    }
    return removeX(input + 1);
}

// return all String subsequences 
int stringSubSeq(string input,string output[]){
    
    // Base Condition
    if(input.empty()){
        output[0] = " ";
        return 1;
    }

    string smallString = input.substr(1);

    // Recursive Call
    int smallOutputSize = stringSubSeq(smallString,output);
    for(int i = 0;i<smallOutputSize;i++){
        output[i+smallOutputSize] = input[0] + output[i];
    }
    return 2*smallOutputSize;
}

// return keypad
int keypad(int num,string output[]){
    // Base Condition
    if(num==0){
        output[0] = " ";
        return 1;
    }

    string input;

    // Recursive Call
    int smallOutputSize = keypad(num/10,output);

    // assign string based on the num%10 single digit number
    switch(num%10){
        case 2: input = "abc";break;
        case 3: input = "def";break;
        case 4: input = "ghi";break;
        case 5: input = "jkl";break;
        case 6: input = "mno";break;
        case 7: input = "pqrs";break;
        case 8: input = "tuv";break;
        case 9: input = "wxyz";break;
    }

    // total solution size will be the already existing output size from recursion times the length of the current input string calculated in the switch case
    int ans_size = smallOutputSize * input.size();
    int k = 0;
    string temp[ans_size];

    // output consists results from previous recursion steps and input consists the current string
    // the output array is copied the same number of times as the length of input string from switch case

    for(int i = 0;i<smallOutputSize;i++){
        for(int j = 0;j<input.size();j++){
            temp[k] = output[i] + input[j];
            k++; 
        }
    }

    // copying elements from temp to output array
    for(int i = 0;i<ans_size;i++) output[i] = temp[i];

    // returning the size of the output array
    return ans_size;
}


// Return subsets
int subsets(int input[],int n,int output[][20]){
    // Base Condition
    if(n<=0){
        output[0][0] = 0;
        return 1;
    }

    // Recursive call
    int count = subsets(input+1,n-1,output);
    for(int i=0;i<count;i++){
        int col = output[i][0] + 1;
        output[i+count][0] = col;
        output[i+count][1] = input[0];
        for(int j = 2;j<col;j++){
            output[count+i][j] = output[i][j-1];
        }
    }
    return 2 * count;
}