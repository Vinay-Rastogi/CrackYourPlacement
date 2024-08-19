#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string findOrder(string dict[], int N, int K) {
        vector<int> InDeg(K, 0);
        vector<int> adj[K];
        
        for (int i = 0; i < N - 1; i++) {
            string str1 = dict[i], str2 = dict[i + 1];
            int j = 0, k = 0;
            
            while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
                j++, k++;
            
            if (j < str1.size() && k < str2.size()) {
                adj[str1[j] - 'a'].push_back(str2[k] - 'a');
                InDeg[str2[k] - 'a']++;
            }
        }
        
        // Apply Kahn's algorithm (topological sort)
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (InDeg[i] == 0)
                q.push(i);
        }
        
        string ans;
        while (!q.empty()) {
            int Node = q.front();
            q.pop();
            ans += (char)('a' + Node);
            
            for (int j : adj[Node]) {
                InDeg[j]--;
                if (InDeg[j] == 0)
                    q.push(j);
            }
        }
        
        return ans;
    }
};

int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    
    Solution sol;
    string order = sol.findOrder(dict, N, K);
    
    cout << "The order of characters is: " << order << endl;
    
    return 0;
}
