#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> Ans;

        for (int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i)
                    temp.push_back(nums[j]);
            }
            Ans.push_back(temp);
        }         
        
        return Ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> result = sol.subsets(nums);

    // Print the subsets
    cout << "Subsets are:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
