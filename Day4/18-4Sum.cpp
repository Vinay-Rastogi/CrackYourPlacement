#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> res;

        if (nums.size() == 0)
            return res;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int front = j + 1;
                int back = n - 1;

                while (front < back)
                {

                    int twoSum = nums[front] + nums[back];

                    if (twoSum < newTarget)
                        front++;

                    else if (twoSum > newTarget)
                        back--;

                    else
                    {

                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];

                        res.push_back(quadruplet);
                        while (front < back && nums[front] == quadruplet[2])
                            front++;
                        while (front < back && nums[back] == quadruplet[3])
                            back--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                    j++;
            }

            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }

        return res;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> res = sl.fourSum(nums, target);

    for (auto v : res)
    {
        for (int x : v)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}