#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k1, vector<int>& v) {
        vector<vector<int>> curr(k1+1,vector<int>(2,0));
        vector<vector<int>> prev(k1+1,vector<int>(2,0));
        int ans=0;
        for(int k=1;k<=k1;k++) prev[k][0]=-v[0];
        for(int i=1;i<v.size();i++)
        {
            for(int k=1;k<=k1;k++)
            {
                curr[k][0]=max(prev[k-1][1]-v[i],prev[k][0]);
            }
            for(int k=1;k<=k1;k++)
            {
                curr[k][1]=max(prev[k][0]+v[i],prev[k][1]);
                ans=max(ans,curr[k][1]);
            }
            prev=curr;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int k1 = 2;  // Number of transactions
    vector<int> v = {3, 2, 6, 5, 0, 3};  // Example stock prices
    int result = sol.maxProfit(k1, v);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
