#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>&pos1, vector<int>&pos2) {
        if (pos1[0] == pos2[0]) 
            return true;
        if (pos1[1] == pos2[1])
            return true;
        return false;
    }

    int findParent(vector<int>&parent, int node) {
        while(parent[node] != node) { 
            node = parent[node]; 
        }
        return node;
    }

    void merge(vector<int>&parent, int& componentCount, int node1, int node2) {
        int parent1 = findParent(parent, node1);
        int parent2 = findParent(parent, node2);

        if (parent1 != parent2) {
            componentCount--;
            parent[parent1] = parent2;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
      
        int componentCount = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isValid(stones[i], stones[j]))
                    merge(parent, componentCount, i, j);
            }
        }
       
        return (n - componentCount); 
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << sol.removeStones(stones) << endl;

    return 0;
}
