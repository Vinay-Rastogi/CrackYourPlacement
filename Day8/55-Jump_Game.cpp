#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int index = nums.size() - 1;

        for (int i = index - 1; i >= 0; i--)
            if (i + nums[i] >= index)
                index = i;

        return index == 0;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << sl.canJump(nums);

    return 0;
}