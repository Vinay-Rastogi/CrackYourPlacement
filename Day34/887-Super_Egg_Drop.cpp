#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};

int main() {
    Solution solution;
    int K = 2; // Number of eggs
    int N = 6; // Number of floors
    cout << "Minimum number of attempts needed: " << solution.superEggDrop(K, N) << endl;
    return 0;
}
