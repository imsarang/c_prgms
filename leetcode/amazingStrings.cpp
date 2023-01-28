#include<unordered_map>
#include<string>

string amazingStrings(string first, string second,string third) {
    // Write your code here.
    unordered_map<char,int>m;
    for(int i=0;i<first.length();i++){
        m[first[i]]++;
    }
     
    for(int i=0;i<second.length();i++){
        m[second[i]]++;
    }

    for(int i=0;i<third.length();i++){
        if(m.count(third[i])>0){
            m[third[i]]--;
        }
    }
    //cout<<m.size()<<endl;
     /*int  flag=0;
    for(int i =0;i<m.size();i++){
        cout<<m[i]<<" "<<m
        if(m.count(m[i])>0){
            cout<<m[i]<<endl;
            flag=1;
            break;
        } 
    }*/
    int flag=0;
    for(auto x:m){
        if(x.second!=0){
            flag=1;
            break;
        }
    }
    if(flag==0)return "YES";
    else return "NO";
}
