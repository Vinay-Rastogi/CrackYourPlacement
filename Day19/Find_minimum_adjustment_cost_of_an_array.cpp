#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minAdjustmentCost(int A[], int n, int target)
    {
        int m = 100;
        int dp[n][m + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                    dp[i][j] = abs(j - A[i]);
                else
                    dp[i][j] = INT_MAX;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 1; k <= m; k++)
                {
                    if (abs(j - k) > target)
                        continue;
                    else
                    {
                        dp[i][j] = min(dp[i][j], abs(j - A[i]) + dp[i - 1][k]);
                    }
                }
            }
        }

        int count = INT_MAX;
        for (int i = 0; i <= 100; i++)
        {
            count = min(count, dp[n - 1][i]);
        }
        return count;
    }
};

int main()
{
    Solution sl;

    int N = 4;
    int target = 1;
    int arr[] = {1, 3, 0, 3};

    cout << sl.minAdjustmentCost(arr, N, target);

    return 0;
}
