#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> v;
        vector<vector<int>> Res;
        generateCombination(n, 1, k, v, Res);

        return Res;
    }

    void generateCombination(int n, int start, int k, vector<int>& v, vector<vector<int>>& Res)
    {
        if(v.size() == k) 
        {
            Res.push_back(v);
            return;
        }
        for(int i = start; i <= n; ++i)
        {
            v.push_back(i);
            generateCombination(n, i + 1, k, v, Res);
            v.pop_back();
        }
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> result = sol.combine(n, k);

    // Print the result
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
