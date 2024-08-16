#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int u, int parent, vector<int> adj[], vector<bool> &vis, vector<bool> &stk) {
        vis[u] = true;
        stk[u] = true;
        
        for(int v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v, u, adj, vis, stk)) return true;
            }
            else if(stk[v] && parent != v) return true;
        }
        stk[u] = false;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> stk(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis, stk)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];
    
    // Example edges for testing
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    Solution sol;
    bool hasCycle = sol.isCycle(V, adj);
    
    if (hasCycle) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }
    
    return 0;
}
