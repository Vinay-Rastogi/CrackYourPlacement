#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
class Solution
{
public:
    string removeDuplicates(string s, int k)
    {

        vector<pair<char, int>> stack;
        for (auto &c : s)
        {
            if (!stack.empty() && stack.back().first == c)
            {

                stack.back().second++;
            }
            else
            {

                stack.push_back({c, 1});
            }

            if (stack.back().second == k)
            {

                stack.pop_back();
            }
        }

        string result;

        for (auto &p : stack)
        {
            result.append(p.second, p.first);
        }

        return result;
    }
};

int main()
{
    Solution sl;
    int k = 3;
    string s = "deeedbbcccbdaa";

    cout << sl.removeDuplicates(s, k);

    return 0;
}