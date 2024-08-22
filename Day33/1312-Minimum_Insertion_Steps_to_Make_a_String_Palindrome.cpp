#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {

        string str = s;

        reverse(s.begin(), s.end());

        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        for (int j = 0; j < n + 1; j++)
            dp[0][j] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {

                if (str[i - 1] == s[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n - dp[n][n];
    }
};

int main()
{
    Solution sl;

    string s = "zzazz";
    cout << sl.minInsertions(s);

    return 0;
}