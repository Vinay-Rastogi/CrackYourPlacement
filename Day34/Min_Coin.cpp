#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MinCoin(vector<int> nums, int amount) {
        int n = nums.size();
        long dp[n + 1][amount + 1];
        
        // Initialize the dp array
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= amount; j++) {
            dp[0][j] = INT_MAX - 1;
        }
        for (int i = 1, j = 1; j <= amount; j++) {
            if (j % nums[0] == 0) {
                dp[i][j] = j / nums[0];
            } else {
                dp[i][j] = INT_MAX - 1;
            }
        }
        
        // Fill the dp array
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - nums[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        if (dp[n][amount] == INT_MAX - 1) {
            return -1;
        }
        return dp[n][amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5}; // Example coin denominations
    int amount = 11; // Example amount
    
    int result = sol.MinCoin(coins, amount);
    
    if (result != -1) {
        cout << "Minimum coins required: " << result << endl;
    } else {
        cout << "It's not possible to make the amount with the given coins." << endl;
    }
    
    return 0;
}
