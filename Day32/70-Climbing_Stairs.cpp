#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int ptr1 = 1;
        int ptr2 = 1;
        int curr = 0;

        for (int i = 2; i <= n; i++) {
            curr = ptr1 + ptr2;
            ptr2 = ptr1;
            ptr1 = curr;
        }

        return ptr1;
    }
};

int main() {
    Solution sol;
    int n=2;
    
    int result = sol.climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs is: " << result << endl;
    
    return 0;
}
