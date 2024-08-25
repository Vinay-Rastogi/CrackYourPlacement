#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(vector<vector<int>> vec, int i, int j)
    {
        if (vec[i][j] == 2)
        {
            int ans = 1;
            for (int i = 0; i < vec.size(); i++)
            {
                for (int j = 0; j < vec[0].size(); j++)
                {
                    if (vec[i][j] == 0)
                    {
                        ans = 0;
                    }
                }
            }
            return ans;
        }

        int count = 0;
        if (vec[i][j] == 0 || vec[i][j] == 1)
        {
            vec[i][j] = -2;
            if (j + 1 < vec[0].size() && vec[i][j + 1] != -1 && vec[i][j + 1] != -2)
            {
                count += fun(vec, i, j + 1);
            }
            if (i + 1 < vec.size() && vec[i + 1][j] != -1 && vec[i + 1][j] != -2)
            {
                count += fun(vec, i + 1, j);
            }
            if (j - 1 >= 0 && vec[i][j - 1] != -1 && vec[i][j - 1] != -2)
            {
                count += fun(vec, i, j - 1);
            }
            if (i - 1 >= 0 && vec[i - 1][j] != -1 && vec[i - 1][j] != -2)
            {
                count += fun(vec, i - 1, j);
            }
        }
        return count;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int s = 0, e = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    s = i;
                    e = j;
                    break;
                }
            }
        }

        int ans = fun(grid, s, e);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    int result = solution.uniquePathsIII(grid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
