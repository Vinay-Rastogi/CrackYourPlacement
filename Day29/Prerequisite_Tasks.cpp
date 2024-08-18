#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfsCycle(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited,
                  unordered_map<int, bool>& dfsVisited, int node) {
        visited[node] = true;
        dfsVisited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                bool isCycle = dfsCycle(adj, visited, dfsVisited, neighbor);
                if (isCycle) {
                    return true;
                }
            } else if (dfsVisited[neighbor]) {
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }

    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < P; i++) {
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            adj[u].push_back(v);
        }
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                bool isCycle = dfsCycle(adj, visited, dfsVisited, i);
                if (isCycle) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int N = 4; // Number of courses (nodes)
    int P = 3; // Number of prerequisites (edges)
    
    vector<pair<int, int>> prerequisites = {{1,0}, {2, 1}, {3, 2}};
    
    Solution sol;
    if (sol.isPossible(N, P, prerequisites)) {
        cout << "Yes, it's possible to complete all courses without a cycle." << endl;
    } else {
        cout << "No, there's a cycle in the prerequisites." << endl;
    }
    
    return 0;
}
