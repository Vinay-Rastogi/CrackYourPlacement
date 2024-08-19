#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minCashFlow(vector<vector<int>> &t, int n) {
        vector<int> frds(n+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                frds[i] += t[j][i] - t[i][j];
            }
        }
        int minIndex = distance(frds.begin(), min_element(frds.begin(), frds.end()));
        int maxIndex = distance(frds.begin(), max_element(frds.begin(), frds.end()));
        vector<vector<int>> ans(n, vector<int>(n));
        while (frds[minIndex] != frds[maxIndex] && frds[minIndex] != 0) {
            int mini = min(-frds[minIndex], frds[maxIndex]);
            ans[minIndex][maxIndex] += mini;
            frds[minIndex] += mini;
            frds[maxIndex] -= mini;
            minIndex = distance(frds.begin(), min_element(frds.begin(), frds.end()));
            maxIndex = distance(frds.begin(), max_element(frds.begin(), frds.end()));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded example
    int n = 3;
    vector<vector<int>> transactions = {
        {0, 1000, 2000},
        {0, 0, 500},
        {0, 0, 0}
    };

    vector<vector<int>> result = sol.minCashFlow(transactions, n);

    cout << "The minimum cash flow to settle the debts is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] != 0) {
                cout << "Friend " << i << " pays Friend " << j << ": " << result[i][j] << endl;
            }
        }
    }

    return 0;
}
