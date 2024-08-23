#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& mp, int cur, set<int>& visited, vector<int>& ans) {
        if (visited.find(cur) != visited.end()) return;
        ans.push_back(cur);
        visited.insert(cur);
        for (int x : mp[cur]) {
            dfs(mp, x, visited, ans);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;

        for (auto arr : adjacentPairs) {
            mp[arr[0]].push_back(arr[1]);
            mp[arr[1]].push_back(arr[0]);
        }

        int start = 0;

        for (auto x : mp) {
            if (x.second.size() == 1) {
                start = x.first;
                break;
            }
        }

        set<int> visited;
        vector<int> ans;

        dfs(mp, start, visited, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
    
    // Call the function
    vector<int> result = sol.restoreArray(adjacentPairs);
    
    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
