#include<stack>

bool validStackPermutation(vector<int> &first, vector<int> &other){
	// Write your code here.
	stack <int> s;
	int j = 0;
	for(int i = 0;i<first.size();i++){
		s.push(first[i]);
		if(s.top() == other[j]){
			while(!s.empty() && s.top() == other[j]){
				s.pop();
				j++;
			}
		}
	}
	if(s.empty()) return 1;
	return 0;
}