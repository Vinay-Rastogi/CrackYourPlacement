#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxArea(int arr[], int n) {
        stack<int> s;
        int res = 0;
        int tp;
        int curr;

        for (int i = 0; i < n; i++) {
            while (s.empty() == false && arr[s.top()] >= arr[i]) {
                tp = s.top();
                s.pop();
                curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                res = max(res, curr);
            }
            s.push(i);
        }
        while (s.empty() == false) {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res, curr);
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int R = matrix.size();
        if (R == 0) return 0;
        int C = matrix[0].size();
        int mat[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        int res = getMaxArea(mat[0], C);

        for (int i = 1; i < R; i++) {
            for (int j = 0; j < C; j++)
                if (mat[i][j])
                    mat[i][j] += mat[i - 1][j];

            res = max(res, getMaxArea(mat[i], C));
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int maxRectangle = sol.maximalRectangle(matrix);
    cout << "Maximum rectangle area: " << maxRectangle << endl;

    return 0;
}
