#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to determine if a graph can be colored with at most M colors such
    // that no two adjacent vertices of the graph are colored with the same color.
    bool isCheck(bool graph[101][101], int n, vector<int> &color, int i, int c) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] && color[j] == c) {
                return false;
            }
        }
        return true;
    }
    
    void travel(bool graph[101][101], int m, int n, bool &check, vector<int> &color, int i) {
        if (i == n) {
            check = true;
            return;
        }
        for (int c = 1; c <= m; c++) {
            if (isCheck(graph, n, color, i, c)) {
                color[i] = c;
                travel(graph, m, n, check, color, i + 1);
                if (check) {
                    return;
                }
                color[i] = 0;
            }
        }
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        bool check = false;
        travel(graph, m, n, check, color, 0);
        return check;
    }
};

int main() {
    int n = 4; // Number of vertices
    int m = 3; // Number of colors
    int e = 5; // Number of edges
    
    // Initialize adjacency matrix with false (no edges)
    bool graph[101][101] = {false};
    
    // Define the edges
    pair<int, int> edges[] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};
    
    // Populate the adjacency matrix based on edges
    for (int i = 0; i < e; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u][v] = true;
        graph[v][u] = true;
    }
    
    Solution obj;
    if (obj.graphColoring(graph, m, n)) {
        cout << "Yes, the graph can be colored with " << m << " colors.\n";
    } else {
        cout << "No, the graph cannot be colored with " << m << " colors.\n";
    }
    
    return 0;
}
