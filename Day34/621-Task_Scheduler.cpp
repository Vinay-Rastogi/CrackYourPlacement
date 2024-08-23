#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        unordered_map<char, int> mp;

        for (char ch : tasks)
            mp[ch]++;

        priority_queue<int> pq;

        for (auto it : mp)
            pq.push(it.second);

        int ans = 0;

        while (!pq.empty()) {
            int time = 0;
            vector<int> temp;

            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }

            for (auto x : temp)
                if (x)
                    pq.push(x);

            ans += pq.empty() ? time : n + 1;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    
    int result = solution.leastInterval(tasks, n);
    cout << "Minimum intervals required: " << result << endl;

    return 0;
}
