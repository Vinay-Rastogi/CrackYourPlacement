#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);
        for(int j = 0; j < adj[node].size(); j++) {
            if(!visited[adj[node][j]]) {
                dfs(adj[node][j], adj, visited, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> ans;
        dfs(0, adj, visited, ans);
        return ans;
    }
};

// Main function
int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];
    
    // Example graph (0-based index)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(4);
    
    Solution sol;
    vector<int> result = sol.dfsOfGraph(V, adj);
    
    cout << "DFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
