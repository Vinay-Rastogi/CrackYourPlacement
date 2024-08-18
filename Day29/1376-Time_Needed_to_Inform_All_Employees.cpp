#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int headId, vector<int>& informTime, vector<int> adj[]) {
        int maxTime = 0;
        for (auto it : adj[headId]) {
            maxTime = max(maxTime, dfs(it, informTime, adj));
        }
        return informTime[headId] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[100005];
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        return dfs(headID, informTime, adj);
    }
};

int main() {
    int n = 6;
    int headID = 2;
    vector<int> manager = {2, 2, -1, 2, 2, 2};
    vector<int> informTime = {0, 0, 1, 0, 0, 0};

    Solution sol;
    int result = sol.numOfMinutes(n, headID, manager, informTime);
    
    cout << "Total time to inform all employees: " << result << endl;

    return 0;
}
