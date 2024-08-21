#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> Res(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 0)
                Res[i] = Res[i / 2];
            else
                Res[i] = Res[i / 2] + 1;
        }

        return Res;
    }
};

int main()
{
    Solution sol;
    int n = 2;

    vector<int> result = sol.countBits(n);

    cout << "Number of 1s in binary representation of numbers from 0 to " << n << " are:\n";
    for (int i = 0; i <= n; i++)
    {
        cout << i << ": " << result[i] << "\n";
    }

    return 0;
}
