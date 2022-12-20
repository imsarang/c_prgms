/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include<unordered_map>

#include<string>
using namespace std;

int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["abc1"]=2;
    ourmap["abc2"]=3;
    ourmap["abc3"]=4;
    ourmap["abc4"]=5;
    
    unordered_map<string,int>::iterator it=ourmap.begin();
    while(it!=ourmap.end()){
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
        it++;
    }
    return 0;
}
