#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int util(int a, int b, int m, int n, int d, vector<vector<int>> &dp, vector<vector<int>> &vis) {
        if (a == d || b == d) return 0;
        if (dp[a][b] != -1) return dp[a][b];
        if (vis[a][b] == 1) return INT_MAX;
        vis[a][b] = 1;
        int res = INT_MAX;
        
        // Empty jug a and b
        res = min(res, util(0, b, m, n, d, dp, vis));
        res = min(res, util(a, 0, m, n, d, dp, vis));
        
        // Fill jug a and b only if they are empty
        if (a == 0) {
            res = min(res, util(m, b, m, n, d, dp, vis));
        }
        if (b == 0) {
            res = min(res, util(a, n, m, n, d, dp, vis));
        }
        
        // Fill a from b or b from a 
        res = min(res, util(a - min(a, n - b), b + min(a, n - b), m, n, d, dp, vis));
        res = min(res, util(a + min(b, m - a), b - min(b, m - a), m, n, d, dp, vis));
        
        return dp[a][b] = (res == INT_MAX ? INT_MAX : res + 1);
    }

    int minSteps(int m, int n, int d) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        vector<vector<int>> vis(m + 1, vector<int>(n + 1, 0));
        int res = util(0, 0, m, n, d, dp, vis);
        if (res == INT_MAX) return -1;
        else return res;
    }
};

int main() {
    // Hardcoded example input
    int m = 3;  // Capacity of jug 1
    int n = 5;  // Capacity of jug 2
    int d = 4;  // Target amount of water
    
    Solution sol;
    int result = sol.minSteps(m, n, d);
    if (result == -1) {
        cout << "It's impossible to measure exactly " << d << " liters." << endl;
    } else {
        cout << "The minimum number of steps to measure exactly " << d << " liters is: " << result << endl;
    }
    
    return 0;
}
