#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
public:
    int dfs(int row, int col, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        if (dp[row][col] != 0) {
            return dp[row][col];
        }

        int maxLength = 1;
        
        for (int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] > mat[row][col]) {
                maxLength = max(maxLength, 1 + dfs(nr, nc, mat));
            }
        }

        return dp[row][col] = maxLength;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, 0));

        int maxPath = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxPath = max(maxPath, dfs(i, j, matrix));
            }
        }

        return maxPath;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    Solution sol;
    cout << "Longest Increasing Path: " << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}
