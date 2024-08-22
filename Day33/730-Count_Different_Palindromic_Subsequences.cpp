#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    long long int dp[1005][1005];

    long long int solve(string &s, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
        {
            int left = i + 1;
            int right = j - 1;

            while (left <= right && s[left] != s[i])
            {
                left++;
            }

            while (left <= right && s[right] != s[i])
            {
                right--;
            }

            if (left > right)
            {
                return dp[i][j] = (2 * solve(s, i + 1, j - 1) + 2) % MOD;
            }
            else if (left == right)
            {
                return dp[i][j] = (2 * solve(s, i + 1, j - 1) + 1) % MOD;
            }
            else
            {
                return dp[i][j] = (2 * solve(s, i + 1, j - 1) - solve(s, left + 1, right - 1) + MOD) % MOD;
            }
        }
        else
        {
            return dp[i][j] = (solve(s, i + 1, j) + solve(s, i, j - 1) - solve(s, i + 1, j - 1) + MOD) % MOD;
        }
    }

    int countPalindromicSubsequences(string s)
    {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        return solve(s, 0, n - 1);
    }
};

int main()
{
    string s = "bccb";

    Solution solution;
    int result = solution.countPalindromicSubsequences(s);
    cout << result << endl;

    return 0;
}
