#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        int prev = 0;
        int ans = 0;

        for (int curr = 1; curr < intervals.size(); curr++) {
            if (intervals[curr][0] < intervals[prev][1]) {
                ans++;
                if (intervals[curr][1] <= intervals[prev][1]) {
                    prev = curr;
                }
            } else {
                prev = curr;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Minimum number of intervals to remove: " << sol.eraseOverlapIntervals(intervals) << endl;

    return 0;
}
