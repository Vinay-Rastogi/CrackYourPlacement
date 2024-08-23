#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPartition(int n, int arr[]) {
        int sum = 0;
        unordered_set<int> us;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if (sum % 2 != 0) {
            return 0;
        }
        sum /= 2;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> v;
            for (auto j = us.begin(); j != us.end(); j++) {
                int num = arr[i] + *j;
                if (num < sum) {
                    v.push_back(num);
                }
                if (num == sum) {
                    return 1;
                }
            }
            for (int j = 0; j < v.size(); j++) {
                us.insert(v[j]);
            }
            if (arr[i] < sum) {
                us.insert(arr[i]);
            }
            if (arr[i] == sum) {
                return 1;
            }
        }
        return 0;
    }
};

int main() {
    // Hardcoded example test case
    int n = 4;
    int arr[] = {1, 5, 11, 5}; // Example: Array with elements 1, 5, 11, 5

    Solution ob;
    if (ob.equalPartition(n, arr)) {
        cout << "YES\n"; // Expected output: YES
    } else {
        cout << "NO\n";
    }

    return 0;
}
