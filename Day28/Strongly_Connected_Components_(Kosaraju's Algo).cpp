#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to perform DFS and store the finish time in a stack.
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    //Function to perform DFS on the transposed graph.
    void dfs3rdstep(int node, vector<int>& vis, vector<int> adjT[])
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3rdstep(it, vis, adjT);
            }
        }
    }

    //Function to find the number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;

        // 1st step: Calculate the finish time and store it in a stack.
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        // 2nd step: Reverse the edges and store them in adjT.
        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        // 3rd step: Calculate the number of strongly connected components.
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs3rdstep(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);
    adj[1].push_back(0);
    adj[2].push_back(1);

    Solution obj;
    cout << "Number of Strongly Connected Components: " << obj.kosaraju(V, adj) << endl;

    return 0;
}
