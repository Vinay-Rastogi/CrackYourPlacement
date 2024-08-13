#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> st;
        for (int i = mat.size() - 1; i >= 0; i--) {
            st.push(i);
        }
        while (st.size() > 1) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if (mat[first][second] && !mat[second][first])
                st.push(second);
            else if (!mat[first][second] && mat[second][first])
                st.push(first);
        }
        if (st.empty())
            return -1;
        int num = st.top();
        st.pop();
        int row = 0;
        int col = 0;
        for (int i = 0; i < mat.size(); i++) {
            row += mat[num][i];
            col += mat[i][num];
        }
        return row == 0 && col == mat.size() - 1 ? num : -1;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}
    };

    Solution sol;
    int result = sol.celebrity(mat);
    cout << "Celebrity ID: " << result << endl;

    return 0;
}
