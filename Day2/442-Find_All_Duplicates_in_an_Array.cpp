#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        vector<int> Res;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        for (auto it : mp)
        {
            if (it.second == 2)
                Res.push_back(it.first);
        }

        return Res;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = sl.findDuplicates(nums);

    for (int x : res)
        cout << x << " ";

    return 0;
}