#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> findCoordinates(int curr, int n) {
        int r = n - (curr - 1) / n - 1;
        int c = (curr - 1) % n;

        if (r % 2 == n % 2) 
            return {r, n - 1 - c};
        else 
            return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push(1);
        visited[n - 1][0] = true;

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int x = q.front();
                q.pop(); // Pop the element before processing it

                if (x == n * n)
                    return steps;

                for (int k = 1; k <= 6; k++) {
                    if (k + x > n * n)
                        break;

                    pair<int, int> pos = findCoordinates(k + x, n);
                    int r = pos.first;
                    int c = pos.second;

                    if (visited[r][c])
                        continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1)
                        q.push(k + x);
                    else
                        q.push(board[r][c]);
                }
            }
            
            steps++;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {0, -1, -1, -1, -1, -1}
    };
    
    int result = sol.snakesAndLadders(board);
    cout << "Minimum number of moves required: " << result << endl;

    return 0;
}
