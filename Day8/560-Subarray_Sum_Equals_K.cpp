#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        mp[sum] = 1;

        for (auto it : nums)
        {

            sum += it;
            int find = sum - k;

            if (mp.find(find) != mp.end())
                ans += mp[find];

            mp[sum]++;
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << sl.subarraySum(nums, k);

    return 0;
}