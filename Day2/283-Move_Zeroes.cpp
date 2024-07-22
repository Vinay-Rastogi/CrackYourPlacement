#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        if (nums.size() < 1)
            return;

        int k = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                nums[k++] = nums[i];

        for (int i = k; i < nums.size(); i++)
            nums[i] = 0;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {0, 1, 0, 3, 12};
    sl.moveZeroes(nums);

    for(int x:nums)
    cout << x << " ";

    return 0;
}