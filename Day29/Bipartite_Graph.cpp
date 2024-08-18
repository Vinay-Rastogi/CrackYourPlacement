#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int start, int V, vector<int> adj[], vector<int> &color) {
        queue<int> q;
        
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            
            for (auto it : adj[num]) {
                if (color[it] == -1) {
                    color[it] = !color[num];  // color the adjacent nodes as opposite
                    q.push(it);
                } else if (color[it] == color[num]) {
                    return false;
                }
            }
        }
        return true;        
    }
    
public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (check(i, V, adj, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    // Example input
    int V = 4;
    int E = 5;
    vector<int> adj[V];
    
    // Hard-coded edges for the example graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);
    adj[0].push_back(2);
    adj[2].push_back(0);
    
    Solution sol;
    if (sol.isBipartite(V, adj)) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is not Bipartite" << endl;
    }
    
    return 0;
}
