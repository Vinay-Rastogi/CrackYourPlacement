#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int copyMaxSoFar = maxSoFar;
            int el = nums[i];

            maxSoFar = max(el, max(maxSoFar * el, minSoFar * el));
            minSoFar = min(el, min(copyMaxSoFar * el, minSoFar * el));

            res = max(res, maxSoFar);
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, -2, 4};
    int result = solution.maxProduct(nums);
    cout << "Maximum product of subarray: " << result << endl;
    return 0;
}
