#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findFloor(vector<long long> &v, long long n, long long x)
    {

        long long left = 0;
        long long right = n - 1;
        long long result = -1;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (v[mid] == x)
                return mid;
            else if (v[mid] < x)
            {
                result = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return result;
    }
};

int main()
{
    Solution sl;
    long long n = 7;
    long long x = 0;
    vector<long long> arr = {1, 2, 8, 10, 11, 12, 19};

    cout << sl.findFloor(arr, n, x);

    return 0;
}