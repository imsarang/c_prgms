#include <string>
#include<string.h>
#include <vector>
#include <algorithm>

using namespace std;

// auto : return type of variable/function automatically deducted/known from its initializer

void mySwap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
// reverse word wise
// first reverse the entire input string and then reverse each word according to spaces in the input string
// take z = i-1 if input[i]!='\0'
// k = i+1 after reversing one word

void reverseWordWise(char input[], int n)
{
    int i, z, k = 0, j = n;
    for (int i = 0; i < j; i++)
    {
        mySwap(&input[i], &input[j]);
        j--;
    }

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i + 1] == '\0')
            z = i;
        else
            z = i - 1;

        if (input[i] == ' ' || input[i + 1] == '\0')
        {
            while (z >= k)
            {
                mySwap(&input[z], &input[k]);
                z--;
                k++;
            }
            k = i + 1;
        }
    }
}

// print all substrings
// run three loops
// the third loop var will run b/w first and second var
vector<string> printSubStr(char input[])
{
    vector<string> ans;
    // vector <char> word;
    for (int i = 0; input[i] != '\0'; i++)
    {
        for (int j = 0; j < input[j] != '\0'; j++)
        {
            string s = "";
            for (int k = i; k <= j; k++)
            {
                s += input[k];
            }
            ans.push_back(s);
        }
    }
    // to remove empty strings from a vector of strings
    auto isEmptyOrBlank = [](const string &s)
    {
        return s.find_first_not_of(" ") == string::npos;
    };

    // erase function of vectors that searches from first to last element to erase/remove element based on the third parameter i.e condition function/filter
    // in our case : erase function erases empty strings in vector of strings based on the function isEmptyOrBlank which acts as a filter
    ans.erase(remove_if(ans.begin(), ans.end(), isEmptyOrBlank), ans.end());

    return ans;
}

// is Permutation
bool isPermutation(char input1[], char input2[])
{
    int i, c[256] = {0};
    for (i = 0; input1[i] && input2[i]; i++)
    {
        c[input1[i]]++;
        c[input2[i]]--;
    }

    if (input1[i] || input2[i])
        return false;
    for (int i = 0; i < 256; i++)
    {
        if (c[i] != 0)
            return false;
    }

    return true;
}

// remove consectuive duplicates :
// initialize index = 1 since the solution shold be in-place and the first character will always be in the answer
void removeDup(char input[])
{
    int index = 1;
    char last = input[0];
    for (int i = 1; input[i]; i++)
    {
        if (last != input[i])
        {
            last = input[i];
            input[index] = input[i];
            index++;
        }
    }
    input[index] = '\0';
}

// reverse each word
void reverseEachWord(char input[])
{
    int i, k = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        int z;
        if (input[i + 1] == '\0')
        {
            z = i;
            while (k < z)
            {
                mySwap(&input[k], &input[z]);
                k++;
                z--;
            }
        }

        if (input[i] == ' ')
        {
            z = i - 1;
            while (k < z)
            {
                mySwap(&input[k], &input[z]);
                k++;
                z--;
            }
            k = i + 1;
        }
    }
}


// compress string
// xxxxxbdfee = x5bdfe2

string compressString(char input[]){
    string str="";
    int count=1;
    for(int i = 0;input[i];i++){
        if(input[i]!=input[i+1]){
            str+=input[i];
            if(count!=1){
                str+=(char)(count+'0');
            }
            count = 1;
        }
        else count++;
    }

    return str;
}

// minimum length word
void getMinLengthWord(char input[],int n,char output[]){
    int minStart = -1;
    int minLength = n;
    int currentStart = 0;
    int i = 0;
    int len = strlen(input);
    for(; i < len; i++){ 
        if(input[i] == ' '){
            int currentWordLength = i - currentStart;
            if(currentWordLength < minLength){
                minStart = currentStart; 
                minLength = currentWordLength;
            }
            currentStart = i + 1;
        }
    }
    if(minStart == -1){
        for(int i = 0; i <= len; i++) { 
            output[i] = input[i];
        }
    }
    else{
        int currentWordLength = i - currentStart;
        if(currentWordLength < minLength){
            minStart = currentStart;
            minLength = currentWordLength;
        } 
        int j = 0;
        for(int i = minStart; i < minStart + minLength; i++) {
            output[j++] = input[i];
        }
        output[j] = '\0';
    }
}