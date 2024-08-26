#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> vec;

    NumArray(vector<int>& nums) {
        this->vec = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += vec[i];
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};  // Example input
    NumArray* obj = new NumArray(nums);

    int left = 1, right = 3;  // Example range
    int result = obj->sumRange(left, right);

    cout << "Sum of range (" << left << ", " << right << ") is: " << result << endl;

    delete obj;  // Free the allocated memory
    return 0;
}
