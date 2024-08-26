#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool safe(int x, int y, int n, vector<vector<int>> &m)
    {
        return (x >= 0 && x < n && y >= 0 && y < n && m[x][y] != 0);
    }

    bool fn(vector<vector<int>> &m, vector<vector<int>> &vis, int x, int y, int n)
    {
        if (x == n - 1 && y == n - 1)
        {
            vis[x][y] = 1;
            return true;
        }
        if (safe(x, y, n, m) && !vis[x][y])
        {
            vis[x][y] = 1;
            for (int i = 1; i <= m[x][y] && i < n; i++)
            {
                if (fn(m, vis, x, y + i, n))
                    return true;
                if (fn(m, vis, x + i, y, n))
                    return true;
            }
            vis[x][y] = 0;
            return false;
        }
        return false;
    }

    vector<vector<int>> ShortestDistance(vector<vector<int>> &m)
    {
        int n = m.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (fn(m, vis, 0, 0, n) == false)
            return {{-1}};
        return vis;
    }
};

int main()
{
    vector<vector<int>> m = {
        {2, 1, 0, 0},
        {2, 0, 0, 1},
        {0, 1, 0, 1}};

    Solution sol;
    vector<vector<int>> result = sol.ShortestDistance(m);

    for (auto &row : result)
    {
        for (auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
