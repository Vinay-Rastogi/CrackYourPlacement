#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {

            if (mp.find(target - nums[i]) != mp.end())
                return {mp[target - nums[i]], i};

            else
                mp[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = sl.twoSum(nums, target);

    for (int x : res)
        cout << x << " ";

    return 0;
}