#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool arraySortedOrNot(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sl;
    vector<int> arr = {10, 20, 30, 40, 50};

    cout << sl.arraySortedOrNot(arr);

    return 0;
}