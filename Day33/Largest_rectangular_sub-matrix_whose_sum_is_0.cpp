#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> mat) {
        int n = mat.size(), m = mat[0].size();
        int sr = -1, sc = -1, er = -1, ec = -1;

        for (int col = 0; col < m; col++) {
            vector<int> ps(n, 0);
            for (int j = col; j < m; j++) {
                for (int i = 0; i < n; i++)
                    ps[i] = ps[i] + mat[i][j];

                unordered_map<int, int> mp;
                int preSum = 0;
                for (int i = 0; i < n; i++) {
                    preSum += ps[i];
                    int vert = (er == -1) ? 0 : (er - sr + 1);
                    int hori = (ec - sc + 1);
                    int cHori = (j - col + 1);
                    int cVert;

                    if (preSum == 0) {
                        cVert = i + 1;
                        int size = vert * hori;
                        int cSize = cVert * cHori;

                        if (cSize > size) {
                            sr = 0;
                            er = i;
                            sc = col;
                            ec = j;
                        }
                    } else if (mp.find(preSum) != mp.end()) {
                        cVert = (i - mp[preSum]);

                        int size = vert * hori;
                        int cSize = cVert * cHori;

                        if (cSize > size) {
                            sr = mp[preSum] + 1;
                            er = i;
                            sc = col;
                            ec = j;
                        }
                    } else {
                        mp[preSum] = i;
                    }
                }
            }
        }

        vector<vector<int>> res;
        for (int i = sr; i <= er; i++) {
            vector<int> psh;
            for (int j = sc; j <= ec; j++)
                psh.push_back(mat[i][j]);
            res.push_back(psh);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, -3},
        {-1, 4, 2},
        {3, -4, -1}
    };

    Solution sol;
    vector<vector<int>> result = sol.sumZeroMatrix(mat);

    cout << "Submatrix with sum zero:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
