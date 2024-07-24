#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        int i = 0;
        int j = 0;
        int currSum = 0;
        int totalSum = 0;
        int ans = 0;

        for (auto i : cardPoints)
            totalSum += i;

        if (k == cardPoints.size())
            return totalSum;

        while (j < cardPoints.size())
        {
            currSum += cardPoints[j];

            if (j - i + 1 < cardPoints.size() - k)
            {
                j++;
            }
            else
            {
                ans = max(ans, totalSum - currSum);
                currSum -= cardPoints[i];
                i++;
                j++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << sl.maxScore(cardPoints, k);

    return 0;
}