#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

          sort(nums.begin(),nums.end());

        
          for(int i=1;i<nums.size();i++)
            if(nums[i] == nums[i-1])
             return nums[i];
        
        return -1;
    }
};

int main(){

    Solution sl;
    vector<int> nums = {1,3,4,2,2};

    cout << sl.findDuplicate(nums);
    
    return 0;
}