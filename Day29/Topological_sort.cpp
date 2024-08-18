#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, st, vis, adj);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }
        vector<int> top_sort;
        while (!st.empty())
        {
            top_sort.push_back(st.top());
            st.pop();
        }
        return top_sort;
    }
};

int main()
{
    // Example usage
    int V = 6;
    vector<int> adj[V];
    
    // Creating the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    Solution sol;
    vector<int> result = sol.topoSort(V, adj);
    
    // Print the result
    cout << "Topological Sort Order: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
