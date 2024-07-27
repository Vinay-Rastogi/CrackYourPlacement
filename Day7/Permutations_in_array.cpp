#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPossible(long long a[], long long b[], int n, long long k)
    {
        // Your code goes here

        sort(a, a + n);
        sort(b, b + n, greater<long long>());

        for (int i = 0; i < n; i++)
            if (a[i] + b[i] < k)
                return false;

        return true;
    }
};

int main()
{

    Solution sl;

    long long a[] = {2, 1, 3};
    long long b[] = {7, 8, 9};
    int n = 3;
    long long k = 10;

    cout << sl.isPossible(a, b, n, k);

    return 0;
}