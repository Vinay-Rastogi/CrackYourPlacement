#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        // Min-heap to store points with their distances
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Calculate the distance of each point from the origin and push to the priority queue
        for(auto it : points) {
            int td = it[0] * it[0] + it[1] * it[1];
            pq.push({td, {it[0], it[1]}});
        }

        // Extract the k closest points
        while(k--) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    vector<vector<int>> result = sol.kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:" << endl;
    for(auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}
