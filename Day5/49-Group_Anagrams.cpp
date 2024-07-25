#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> Res;

        for (auto x : strs)
        {

            string temp = x;
            sort(x.begin(), x.end());
            mp[x].push_back(temp);
        }

        for (auto x : mp)
            Res.push_back(x.second);

        return Res;
    }
};

int main()
{
    Solution sl;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = sl.groupAnagrams(strs);

    for (auto v : res)
    {
        for (string s : v)
            cout << s << " ";

        cout << endl;
    }

    return 0;
}