#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        sort(strs.begin(), strs.end());

        string ans = "";

        for (int i = 0; i < strs[0].size(); i++)
        {

            if (strs[0][i] != strs[strs.size() - 1][i])
                return ans;

            ans += strs[0][i];
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<string> strs = {"flower", "flow", "flight"};

    cout << sl.longestCommonPrefix(strs);

    return 0;
}