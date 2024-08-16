#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of the given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V = 5; // Number of vertices in the graph
    vector<int> adj[V];

    // Example graph: 
    // 0 -> 1, 2
    // 1 -> 0, 3, 4
    // 2 -> 0
    // 3 -> 1
    // 4 -> 1
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(1);

    Solution obj;
    vector<int> bfs = obj.bfsOfGraph(V, adj);

    // Print the BFS traversal
    for (int i : bfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
