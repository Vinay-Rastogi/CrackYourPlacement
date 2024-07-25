#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        long long int i = 0, j = height.size() - 1, maxi = INT_MIN;
        while (i < j)
        {

            maxi = max(maxi, (j - i) * (min(height[i], height[j])));
            if (height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxi;
    }
};

int main()
{
    Solution sl;
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << sl.maxArea(heights);

    return 0;
}