#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) {
        int tank = 0, total = 0, index = 0;
        for(int i = 0; i < A.size(); i++) {
            int consume = A[i] - B[i];
            tank += consume;
            if(tank < 0) {
                tank = 0;
                index = i + 1;
            }
            total += consume;
        }
        if(total >= 0) return index;
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 1, 2};
    
    int result = sol.canCompleteCircuit(A, B);
    
    if(result != -1) {
        cout << "Starting gas station: " << result << endl;
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
