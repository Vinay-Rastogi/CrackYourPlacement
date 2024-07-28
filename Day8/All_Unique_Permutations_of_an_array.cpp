#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        // code here
        vector<vector<int>> perm;

        sort(arr.begin(), arr.end());

        do
        {
            perm.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));

        return perm;
    }
};

int main()
{

    Solution sl;
    vector<int> arr = {1, 2, 1};
    int n = 3;

    vector<vector<int>> res = sl.uniquePerms(arr, n);

    for (auto v : res)
    {

        for (int i : v)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}