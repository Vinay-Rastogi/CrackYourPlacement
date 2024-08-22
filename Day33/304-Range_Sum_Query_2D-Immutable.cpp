#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> mat;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        mat = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = matrix[i - 1][j - 1] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return mat[row2 + 1][col2 + 1] - mat[row1][col2 + 1] - mat[row2 + 1][col1] + mat[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix obj(matrix);
    
    cout << "Sum of region (2, 1) to (4, 3): " << obj.sumRegion(2, 1, 4, 3) << endl;
    cout << "Sum of region (1, 1) to (2, 2): " << obj.sumRegion(1, 1, 2, 2) << endl;
    cout << "Sum of region (1, 2) to (2, 4): " << obj.sumRegion(1, 2, 2, 4) << endl;

    return 0;
}
