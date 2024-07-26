#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int left = m - 1;
        int right = 0;

        while (left >= 0 && right < n)
        {

            if (nums1[left] > nums2[right])
            {
                swap(nums1[left], nums2[right]);
                right++;
                left--;
            }
            else
            {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        for (int i = 0; i < nums2.size(); i++)
            nums1[m + i] = nums2[i];
    }
};

int main()
{
    Solution sl;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sl.merge(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";

    return 0;
}