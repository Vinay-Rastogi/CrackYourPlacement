#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            
            if (dp[i] == dp[p2] * 2)
                p2++;
            if (dp[i] == dp[p3] * 3)
                p3++;
            if (dp[i] == dp[p5] * 5)
                p5++;
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    int n=10;
    int result = sol.nthUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << result << endl;
    return 0;
}
