#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int i, int j, int *keys, int *freq, vector<vector<int>> &dp) {
        if (i == j) {
            return freq[i];
        }

        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int cur = 0;
        for (int k = i; k <= j; k++) {
            cur += freq[k];
        }

        int ans = INT_MAX;
        for (int k = i; k <= j; k++) {
            int left = solve(i, k - 1, keys, freq, dp);
            int right = solve(k + 1, j, keys, freq, dp);
            ans = min(ans, left + right + cur);
        }
        return dp[i][j] = ans;
    }

public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, keys, freq, dp);
    }
};

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    Solution sol;
    cout << "Cost of the optimal search tree is: " << sol.optimalSearchTree(keys, freq, n) << endl;

    return 0;
}
