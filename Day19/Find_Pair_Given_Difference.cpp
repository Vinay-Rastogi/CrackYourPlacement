#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        // 2 3 5 5 20 80
        int left = 0;
        int right = 1;
        while (left < n && right < n)
        {
            int temp = (arr[right] - arr[left]);
            if (temp == x && left != right)
                return 1;
            else if (temp > x)
                left++;
            else
                right++; // if(i==j)  j++;
        }
        return -1;
    }
};

int main()
{
    Solution sl;

    int n = 6;
    int x = 78;
    vector<int> arr = {5, 20, 3, 2, 5, 80};

    cout << sl.findPair(n, x, arr);

    return 0;
}