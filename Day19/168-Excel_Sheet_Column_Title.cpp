#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {

        string res = "";

        while (columnNumber > 0)
        {

            int last = columnNumber % 26;
            if (last == 0)
            {
                last = 90;
            }

            else
            {
                last = last + 64;
            }

            res = res + char(last);
            columnNumber = (columnNumber - 1) / 26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution sl;
    int columnNumber = 1;

    cout << sl.convertToTitle(columnNumber);

    return 0;
}