#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<vector<int>> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > s.top()[0]) {
                res[s.top()[1]] = i - s.top()[1];
                s.pop();
            }
            s.push({temperatures[i], i});
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(temperatures);

    cout << "Days until a warmer temperature: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
