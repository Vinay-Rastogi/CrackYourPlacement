#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        if (nums.size() < 3)
            return {};

        int n = nums.size();
        vector<vector<int>> Ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int j = i + 1;
                int k = n - 1;

                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                    {
                        Ans.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1])
                            j++;
                        while (j < k && nums[k] == nums[k - 1])
                            k--;
                        j++;
                        k--;
                    }

                    else if (sum > 0)
                        k--;
                    else
                        j++;
                }
            }
        }

        return Ans;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sl.threeSum(nums);

    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}