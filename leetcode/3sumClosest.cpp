#include<vector>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
        int k = nums.size()-1;            
        while(j < k) {
            int curSum = nums[i]+nums[j]+nums[k];
            if(curSum == target) return curSum;
            if(abs(target-curSum)<abs(target-ans)) {
                ans = curSum;
            }
            if(curSum > target) {
                --k;
            } else {
                ++j;
            }
        }
        }
        return ans;
    }
};