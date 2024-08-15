#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catalan_Number(int n) {
        vector<int> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[n];
    }

    int numTrees(int n) {
        return catalan_Number(n);
    }
};

int main() {
    Solution sl;
    int n = 3;
    
    int result = sl.numTrees(n);
    cout << "The number of unique BSTs that can be formed with " << n << " nodes is: " << result << endl;

    return 0;
}
