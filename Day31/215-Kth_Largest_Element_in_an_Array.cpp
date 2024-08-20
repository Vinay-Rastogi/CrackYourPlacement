#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        int val;
        
        while(k){
            val = pq.top();
            pq.pop();
            k--;
        }
        
        return val;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    int result = sol.findKthLargest(nums, k);
    
    cout << "The " << k << "th largest element is: " << result << endl;
    
    return 0;
}
