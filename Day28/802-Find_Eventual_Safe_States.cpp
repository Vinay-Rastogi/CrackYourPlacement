#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> inDegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjRev[node]) {
                inDegree[it]--;

                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    
    vector<int> safeNodes = sol.eventualSafeNodes(graph);
    
    cout << "Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
