#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    void rotate(vector<vector<int>> &matrix)
    {

        int m = matrix.size();

        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Reversing the columns

        for (int i = 0; i < m; i++)
        {
            for (int j = 0, k = m - 1; j < m / 2; j++, k--)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
        }
    }
};

int main()
{
    Solution sl;

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    sl.rotate(matrix);

    for (auto v: matrix)
    {
        for (int i : v)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}