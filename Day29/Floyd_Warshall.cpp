#include <iostream>
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Replace -1 with a large number to indicate infinity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        
        // Floyd-Warshall algorithm to compute shortest distances
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }
        
        // Replace INT_MAX back to -1 to indicate no path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MAX) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0, 3, -1, -1},
        {2, 0, -1, 1},
        {-1, 7, 0, -1},
        {-1, -1, 2, 0}
    };
    
    Solution sol;
    sol.shortest_distance(matrix);
    
    // Print the updated matrix
    cout << "Shortest distance matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << (val == INT_MAX ? -1 : val) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
