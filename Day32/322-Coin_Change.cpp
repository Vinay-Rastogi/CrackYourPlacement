#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int> prev(amt + 1), curr(amt + 1);
        for (int i = 0; i <= amt; i++) {
            if (i % coins[0] == 0) prev[i] = (i / coins[0]);
            else prev[i] = 1e9;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amt; j++) {
                int notTake = prev[j];
                int take = 1e9;
                if (coins[i] <= j) take = 1 + curr[j - coins[i]];
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amt];
        if (ans == 1e9) return -1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}
