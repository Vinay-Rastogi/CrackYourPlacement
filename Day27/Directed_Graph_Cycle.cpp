#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inedge(V);
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                inedge[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inedge[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int topNode = q.front();
            q.pop();
            count++;
            for (auto i : adj[topNode]) {
                inedge[i]--;
                if (inedge[i] == 0) {
                    q.push(i);
                }
            }
        }
        return count != V;
    }
};

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution sol;
    if (sol.isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
