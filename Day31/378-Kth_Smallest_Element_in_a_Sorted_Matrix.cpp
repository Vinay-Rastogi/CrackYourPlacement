#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> Res;
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Res.push_back(matrix[i][j]);
            }
        }
        
        sort(Res.begin(), Res.end());
        
        return Res[k-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    int result = sol.kthSmallest(matrix, k);
    cout << "The " << k << "th smallest element is: " << result << endl;
    
    return 0;
}
