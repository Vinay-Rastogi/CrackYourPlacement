#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void helper(vector<vector<char>> &grid, int i, int j)
    {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;

        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        helper(grid, i + 1, j);
        helper(grid, i - 1, j);
        helper(grid, i, j - 1);
        helper(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int ans = 0;

        for (int l = 0; l < grid.size(); l++)
        {

            for (int m = 0; m < grid[0].size(); m++)
            {

                if (grid[l][m] == '1')
                {
                    helper(grid, l, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};

    cout << sl.numIslands(grid);

    return 0;
}