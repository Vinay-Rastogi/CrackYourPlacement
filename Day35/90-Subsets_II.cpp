#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> Ans;
        set<vector<int>> Myset;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                if((1 << j) & i)
                    temp.push_back(nums[j]);
            }
            Myset.insert(temp);
        }

        for(auto it : Myset)
            Ans.push_back(it);

        return Ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = solution.subsetsWithDup(nums);

    cout << "The subsets with duplicates removed are:" << endl;
    for(const auto& subset : result) {
        cout << "[ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
