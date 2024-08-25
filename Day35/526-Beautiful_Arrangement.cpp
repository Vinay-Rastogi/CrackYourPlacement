#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int count(int mask, int i, int n) {
        if (i == n) return 1;

        if (dp[mask] != -1) return dp[mask];
        
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if ((mask & (1 << (j - 1))) && (j % (i + 1) == 0 || (i + 1) % j == 0)) {
                mask = mask ^ (1 << (j - 1));
                ans += count(mask, i + 1, n);
                mask = mask ^ (1 << (j - 1));
            }
        }

        return dp[mask] = ans;
    }

    int countArrangement(int n) {
        int mask = 1 << n;
        dp.resize(mask, -1);
        mask--;
        return count(mask, 0, n);
    }
};

int main() {
    Solution sol;
    int n = 3;  // Hardcoded example input
    cout << "The number of beautiful arrangements for n = " << n << " is: " << sol.countArrangement(n) << endl;
    return 0;
}
