#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int count_0 = 0;
        int count_1 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count_0++;

            if (nums[i] == 1)
                count_1++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < count_0)
                nums[i] = 0;

            else if (i >= count_0 && i < count_0 + count_1)
                nums[i] = 1;

            else
            {
                nums[i] = 2;
            }
        }
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sl.sortColors(nums);

    for (int x : nums)
        cout << x << " ";

    return 0;
}