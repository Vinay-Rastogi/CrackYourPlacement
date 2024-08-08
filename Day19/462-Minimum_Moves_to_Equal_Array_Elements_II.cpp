#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int ans = 0;
        for (auto val : nums)
            ans += abs(mid - val);
        return ans;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {1, 2, 3};

    cout << sl.minMoves2(nums);

    return 0;
}