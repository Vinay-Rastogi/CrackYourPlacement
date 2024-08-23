#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0;
        int ans = 0;

        while(i < colors.size() - 1) {
            if(colors[i] == colors[i + 1]) {
                int j = i + 1;
                while(j < colors.size() && colors[i] == colors[j]) {
                    if(neededTime[i] <= neededTime[j]) {
                        ans += neededTime[i];
                        i = j;
                        j++;
                    } else {
                        ans += neededTime[j];
                        j++;
                    }
                }
                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string colors = "aabaa";
    vector<int> neededTime = {1, 2, 3, 4, 5};

    int result = sol.minCost(colors, neededTime);
    cout << "Minimum cost to remove balloons: " << result << endl;

    return 0;
}
