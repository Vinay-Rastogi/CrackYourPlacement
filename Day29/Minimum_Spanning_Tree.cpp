#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int find(int x, vector<int>& par) {
        if(x == par[x]) {
            return x;
        }
        return par[x] = find(par[x], par);
    }

    void Union(int x, int y, vector<int>& par, vector<int>& rank) {
        int par_x = find(x, par);
        int par_y = find(y, par);

        if(par_x == par_y) return;

        if(rank[par_x] > rank[par_y]) {
            par[par_y] = par_x;
        } else if(rank[par_x] < rank[par_y]) {
            par[par_x] = par_y;
        } else {
            par[par_x] = par_y;
            rank[par_y]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> vec;
        for(int i = 0; i < V; i++) {
            for(auto &it : adj[i]) {
                vec.push_back({it[1], i, it[0]});
            }
        }

        sort(vec.begin(), vec.end());
        int ans = 0;
        vector<int> par(V), rank(V, 0);

        for(int i = 0; i < V; i++) par[i] = i;

        for(auto &it : vec) {
            int u = it[1];
            int v = it[2];
            int wt = it[0];

            int par_u = find(u, par);
            int par_v = find(v, par);

            if(par_u != par_v) {
                ans += wt;
                Union(u, v, par, rank);
            }
        }
        return ans;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];

    // Example graph input (u, v, weight)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    Solution obj;
    int mst_weight = obj.spanningTree(V, adj);
    cout << "The sum of weights of the edges in the Minimum Spanning Tree is: " << mst_weight << endl;

    return 0;
}
