#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int majority = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                majority = nums[i];
                count++;
            }
            else if (nums[i] == majority)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return majority;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << sl.majorityElement(nums);

    return 0;
}