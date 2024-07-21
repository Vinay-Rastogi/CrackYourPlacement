#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int n = heights.size();
        int res = 0;
        int tp;
        int curr;

        for (int i = 0; i < n; i++)
        {

            while (s.empty() == false && heights[s.top()] >= heights[i])
            {

                tp = s.top();
                s.pop();
                curr = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                res = max(res, curr);
            }

            s.push(i);
        }

        while (s.empty() == false)
        {

            tp = s.top();
            s.pop();
            curr = heights[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res, curr);
        }

        return res;
    }
};

int main()
{

    Solution sl;
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << sl.largestRectangleArea(heights);

    return 0;
}