#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string binarySum(string arr1,string arr2){
	
	if(arr1.length()==0)return arr1;

	if(arr2.length()==0)return arr1;

	if(arr2.length()<arr1.length()){
		return binarySum(arr2,arr1);
	}
	int diff = arr2.length()-arr1.length();
	string padding;
	for(int i =0;i<diff;i++)
		padding.push_back('0');
	
	arr1 = padding + arr1;
	string output;

	char carry='0';
	
	for(int  i = arr1.length()-1;i>=0;i--){
		if(arr1[i]=='1'  &&  arr2[i]=='1'){
			if(carry=='1')
				output.push_back('1'),carry='1';
			else
				output.push_back('0'),carry='1';
		}else if(arr1[i] == '0' &&  arr2[i] == '0'){
			if(carry=='1')
				output.push_back('1'),carry='0';
			else
				output.push_back('0'),carry='0';
		}
		else if(arr1[i] != arr2[i]){
			if(carry=='1')
				output.push_back('0'),carry = '1';
			else
				output.push_back('1'),carry = '0';
		}
	}

	if(carry=='1')
		output.push_back(carry);

	reverse(output.begin(),output.end());
	return  output;
}

int main() {

	// Write your code here
	int t;
	cin>>t;
	while(t>0){
		string arr1,arr2;
	cin>>arr1;
	cin>>arr2;
	string output = binarySum(arr1,arr2);
	cout<<output<<endl;
	t--;
	}
	
}	
