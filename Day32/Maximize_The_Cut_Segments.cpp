#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int dp[10001];

    int rec(int n, vector<int>& arr) {
        if (n == 0) return 0;
        if (n < 0) return INT_MIN;
        if (dp[n] != -1) return dp[n];

        int temp = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            temp = max(temp, 1 + rec(n - arr[i], arr));
        }
        return dp[n] = temp;
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        memset(dp, -1, sizeof(dp));
        vector<int> arr = {x, y, z};
        int ans = rec(n, arr);
        return ans < 0 ? 0 : ans;
    }
};

int main() {
    // Hardcoded example input
    int n = 4; // Length of the rod
    int x = 2; // Possible cut length 1
    int y = 1; // Possible cut length 2
    int z = 1; // Possible cut length 3
    
    Solution ob;
    cout << ob.maximizeTheCuts(n, x, y, z) << endl;

    return 0;
}
