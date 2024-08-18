#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int> dist(n, 1e9);
        int source = 0;
        dist[source] = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                return 1; // Negative weight cycle exists
            }
        }
        return 0; // No negative weight cycle
    }
};

int main() {
    Solution sol;
    
    int n = 3; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, -2},
        {2, 0, -3},
    };

    int result = sol.isNegativeWeightCycle(n, edges);
    if (result) {
        cout << "Negative weight cycle exists" << endl;
    } else {
        cout << "No negative weight cycle exists" << endl;
    }

    return 0;
}
