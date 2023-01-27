/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

vector<int> removeDuplicates(int* arr,int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i = 0;i<size;i++){
        if(seen.count(arr[i])>0)
        {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

// pair sum to 0
int summation(int x){
	if(x==0)
	return 0;
	else return (x-1)+summation(x-1);
}
int pairSum(int *arr, int n) {
	// Write your code here
	int count = 0;
	unordered_map <int,int> map;
	for(int i = 0;i<n;i++){
		map[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			count+=summation(map[arr[i]]);
			map[arr[i]]=0;
		}
		else if(arr[i]!=0&&map[-arr[i]]>0){
			// int x = maxElem(map[arr[i]],map[-arr[i]]);
			// count+=x;
			// map[-arr[i]]=0;
			count += map[arr[i]]*map[-arr[i]];
			map[arr[i]] = 0;
			map[-arr[i]] = 0;
		}
	}
	return count;
}

// number of pairs with differene equal to k
int summation(int x){
    if(x==0) return 0;
    else return (x-1) + summation(x-1);
}

int pairWithDiffK(int *arr,int n,int k){
    unordered_map <int,int> map;
    for(int i = 0;i<n;i++){
        map[arr[i]]++;
    }

    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == k + arr[i]){
            count += summation(map[arr[i]]);
            map[arr[i]] = 0;
        }
        else if(arr[i] -k>=0 && map[arr[i]-k] > 0){
            count += map[arr[i]] * map[arr[i]-k];
            map[arr[i]] = 0;
        }
        else if(map[k+arr[i]]>0){
            count+=map[arr[i]] *map[arr[i] + k];
            map[arr[i]] = 0;
        }
    }
    return count;
}

// length of longest subset with sum = 0
int longestSubsetWithSum0(int *arr,int n){
    int length = 0;
    int sum = 0;
    unordered_map <int,int> map;
    for(int i = 0;i<n;i++){
        sum +=arr[i];
        if(arr[i] == 0 && length ==0) length = 1;
        if(sum==0) length+=1;
        if(map.count(sum) > 0){
            length = max(length,i-map[sum]);
        }
        else map[sum] = i;
    }
    return length;
}

// return longest consecutive increasing seq
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int> ans;
    unordered_map<int,int> a;
    for(int i=0;i<n;i++)
    {
        a[arr[i]]=1;
    }
    int max=0;
    int k=0;
    
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int j=0;
        if(a.count(x-1)>0)
            continue;
        while(a.count(x)>0 )
        {
                
            j++;
            x++;
        }
        if(j>max)
        {  
            max=j;
            k=arr[i];
            //cout<<" j:"<<j<<" k:"<<k<<endl; 
        }   
    }
    
   
    ans.push_back(k);
    ans.push_back(k+max-1);
    return ans;
}


int main()
{
    unordered_map<string,int> ourMap;
    // insert
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    
    ourMap["def"] = 2;
    
    // get values
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;
    cout<<ourMap["ghi"]<<endl;
    
    // check presence
    if(ourMap.count("hi")>0){
        cout<<"hi is present"<<endl;
    }
    else cout<<"hi is not present"<<endl;
    
    // size:
    cout<<ourMap.size()<<endl;
    
    // erase
    ourMap.erase("ghi");
    
    if(ourMap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    else cout<<"ghi is not present"<<endl;
    cout<<ourMap.size()<<endl;
    
    int arr[] = {2,1,1,1,4,4,5,5,6,7,8,22,3,35,4,7};
    vector<int> ans = removeDuplicates(arr,15);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
