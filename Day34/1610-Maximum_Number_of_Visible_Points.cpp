#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int answer = 0;
        double pi = acos(-1.0);
        vector<double> pointAngles;

        // Iterate through all points to find the required polar angle with respect to location
        for (auto p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                // Points with the same location as yours
                answer += 1;
            } else {
                int dx = p[0] - location[0];
                int dy = p[1] - location[1];
                double angle = atan2(dy, dx); // Gives inverse tangent in radians for a coordinate
                // Convert to degrees
                double angle1 = angle * 180.0 / pi;
                pointAngles.push_back(angle1);
            }
        }

        sort(pointAngles.begin(), pointAngles.end());
        // Sorting the angles to make sure the required count is a contiguous length of angles
        int n = pointAngles.size();
        for (int i = 0; i < n; ++i) {
            pointAngles.push_back(pointAngles[i] + 360);
            // Push the angles again by adding 360 to handle the case of consecutive points
            // being after a complete cycle (e.g., 345 and 14 if angle >= 29)
        }

        int start = 0;
        int cnt = 0;
        // Sliding window of size angle
        for (int i = 0; i < pointAngles.size(); ++i) {
            while (pointAngles[i] - pointAngles[start] > angle) {
                start++;
            }
            cnt = max(cnt, i - start + 1);
        }

        answer += cnt; // Add this length to the number of overlapping points earlier
        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{2, 1}, {2, 2}, {3, 3}};
    int angle = 90;
    vector<int> location = {1, 1};
    
    int result = sol.visiblePoints(points, angle, location);
    cout << "Number of visible points: " << result << endl;

    return 0;
}
