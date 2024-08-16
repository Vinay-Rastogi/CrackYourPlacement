#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
        // Base case: reached the bottom-right corner
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        
        // Downwards
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
            vis[i + 1][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i + 1][j] = 0; 
        }
        
        // Leftwards
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
            vis[i][j - 1] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j - 1] = 0; 
        }
        
        // Rightwards
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
            vis[i][j + 1] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j + 1] = 0; 
        }
        
        // Upwards
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
            vis[i - 1][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i - 1][j] = 0; 
        }
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        if (mat[0][0] == 1) {
            vis[0][0] = 1;
            solve(0, 0, mat, n, ans, "", vis);
        }
        
        return ans;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<string> paths = sol.findPath(mat);
    
    cout << "Paths:\n";
    for (const string& path : paths) {
        cout << path << "\n";
    }

    return 0;
}
