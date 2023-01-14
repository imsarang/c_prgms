#include "allStringProblems.h"
#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
// void printSubStr(char input[]){
//     for(int i =0;input[i]!='\0';i++){
//         for(int j = 0;input[j]!='\0';j++){
//             for(int k = i;k<=j;k++){
//                 cout<<input[k];
//             }
//             cout<<endl;
//         }
//     }
// }
int main(){
    char input[1000];
    cin.getline(input,1000);

    // reverseWordWise(input,1000);

    // vector<string> result = printSubStr(input);
    // for(const auto &s : result){
    //     cout<<s<<endl;
    // }

    // char input2[1000];
    // cin.getline(input2,1000);
    // cout<<isPermutation(input,input2);

    // removeDup(input);

    // reverseEachWord(input);

    // string result = compressString(input);
    // cout<<result;
    char output[1000];
    getMinLengthWord(input,1000,output);
    cout<<output;
    // cout<<input<<endl;   
}


