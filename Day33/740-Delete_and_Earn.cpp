#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {

        int n = 10001;
        vector<int> value(n, 0);

        for (int i = 0; i < nums.size(); i++)
            value[nums[i]] += nums[i];

        int take = 0;
        int skip = 0;

        for (int i = 0; i < n; i++)
        {
            int takei = value[i] + skip;
            int skipi = max(take, skip);

            take = takei;
            skip = skipi;
        }

        return max(skip, take);
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {3, 4, 2};

    cout << sl.deleteAndEarn(nums);

    return 0;
}