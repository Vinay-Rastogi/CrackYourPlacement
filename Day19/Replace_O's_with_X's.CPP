#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void solve(vector<vector<char>> &mat, int i, int j)
    {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] == 's' || mat[i][j] == 'X')
            return;
        mat[i][j] = 's';
        solve(mat, i - 1, j);
        solve(mat, i + 1, j);
        solve(mat, i, j - 1);
        solve(mat, i, j + 1);
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 'O')
                solve(mat, 0, i);
            if (mat[n - 1][i] == 'O')
                solve(mat, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O')
                solve(mat, i, 0);
            if (mat[i][m - 1] == 'O')
                solve(mat, i, m - 1);
        }
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 's')
                    mat[i][j] = 'O';
                else
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

int main()
{
    Solution sl;

    int n = 5;
    int m = 4;
    vector<vector<char>> mat = {{'X', 'O', 'X', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'X', 'O', 'O'}};

    sl.fill(n, m, mat);

    for (auto v : mat)
    {
        for (auto i : v)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}