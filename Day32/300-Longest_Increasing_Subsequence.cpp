#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 1;
        vector<int> LIS(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    LIS[i] = max(LIS[j] + 1, LIS[i]);
                }
            }
        }

        for (int i = 0; i < LIS.size(); i++)
        {
            ans = max(ans, LIS[i]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Example input
    int result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << result << endl;
    return 0;
}
