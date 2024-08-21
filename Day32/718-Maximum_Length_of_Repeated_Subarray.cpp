#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ptr2 = 0;  
        int cnt = 0;
        int largest = INT_MIN;

        // Check subarrays starting from nums1
        for(int i = 0; i < n1; i++) {
            cnt = 0;
            for(int j = i, ptr2 = 0; j < n1 && ptr2 < n2; j++, ptr2++) {
                if (nums1[j] == nums2[ptr2]) {
                    cnt++;
                } else {
                    cnt = 0;
                }
                largest = max(largest, cnt);
            }
        }

        // Check subarrays starting from nums2
        ptr2 = 0;
        cnt = 0;
        for (int i = 0; i < n2; i++) {
            cnt = 0;
            for (int j = i, ptr2 = 0; j < n2 && ptr2 < n1; j++, ptr2++) {
                if (nums2[j] == nums1[ptr2]) {
                    cnt++;
                } else {
                    cnt = 0;
                }
                largest = max(largest, cnt);
            }
        }

        return largest;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    int result = sol.findLength(nums1, nums2);
    cout << "The maximum length of a subarray that appears in both arrays is: " << result << endl;

    return 0;
}
