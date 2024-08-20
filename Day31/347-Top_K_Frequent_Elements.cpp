#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> Res;
       
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> m;
        for(auto i : mp) {
            m.push(make_pair(i.second, i.first));
        }
        
        for(int i = 0; i < k; i++) {
            Res.push_back(m.top().second);
            m.pop();
        }
      
        return Res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> result = sol.topKFrequent(nums, k);
    
    // Print the result
    for(int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
