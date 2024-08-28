#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &v, int k)
    {
        priority_queue<vector<int>> pq; // max heap
        pq.push({v[0][1] - v[0][0], v[0][0]});
        int ans = INT_MIN, sum;
        for (int i = 1; i < v.size(); i++)
        {
            sum = v[i][0] + v[i][1];
            // Remove elements from heap that are out of range `k`
            while (!pq.empty() && v[i][0] - pq.top()[1] > k)
                pq.pop();
            // Check if the heap is not empty, update the answer
            if (!pq.empty())
            {
                ans = max(ans, sum + pq.top()[0]);
            }
            // Push current element into the heap
            pq.push({v[i][1] - v[i][0], v[i][0]});
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{0, 0}, {3, 0}, {9, 2}};
    int k = 3;
    cout << "Maximum value of the equation: " << sol.findMaxValueOfEquation(v, k) << endl;
    return 0;
}
