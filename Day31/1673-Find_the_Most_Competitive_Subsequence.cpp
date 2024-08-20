#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> arr;
        int i = 0;
        for (; i < n - k; i++) {
            arr.push({nums[i], i});
        }
        vector<int> ans;
        int ci = -1;
        for (; i < n; i++) {
            arr.push({nums[i], i});
            while (arr.top()[1] < ci) arr.pop();
            ans.push_back(arr.top()[0]);
            ci = arr.top()[1];
            arr.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 2, 6};
    int k = 2;
    
    vector<int> result = sol.mostCompetitive(nums, k);
    
    cout << "The most competitive subsequence is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
