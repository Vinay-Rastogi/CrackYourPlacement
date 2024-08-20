#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target)
            return 0;

        priority_queue<int> max_heap;
        int i = 0, n = stations.size();
        int stops = 0;
        int max_distance = startFuel;

        // Loop until the car reaches the target or is out of fuel
        while (max_distance < target) {
            // Add fuel to the heap for stations within the current range
            while (i < n && stations[i][0] <= max_distance) {
                max_heap.push(stations[i][1]);
                i++;
            }

            // If there are no more stations in range and we can't reach the target, return -1
            if (max_heap.empty())
                return -1;

            // Refuel with the largest amount available and increment stops
            max_distance += max_heap.top();
            max_heap.pop();
            stops++;
        }

        return stops;
    }
};

int main() {
    Solution sol;

    // Example 1
    int target1 = 100;
    int startFuel1 = 10;
    vector<vector<int>> stations1 = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << "Minimum refuel stops for example 1: " << sol.minRefuelStops(target1, startFuel1, stations1) << endl;

    

    return 0;
}
