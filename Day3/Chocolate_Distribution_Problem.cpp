#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        int i = 0;
        int r = m - 1;
        int mini = INT_MAX;
        int ans = 0;
        while (r < n)
        {
            ans = a[r] - a[i];
            mini = min(mini, ans);
            i++;
            r++;
        }
        return mini;
    }
};

int main()
{
    Solution sl;
    long long n = 8;
    long long m = 5;
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};

    cout << sl.findMinDiff(a, n, m);

    return 0;
}