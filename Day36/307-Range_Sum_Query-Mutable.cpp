#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> tree;
    vector<int> nums;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int index, int val) {
        update(0, 0, nums.size() - 1, index, val);
    }

    void update(int node, int start, int end, int index, int val) {
        if (start == end) {
            nums[index] = val;
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            if (index >= start && index <= mid) 
                update(2 * node + 1, start, mid, index, val);
            else 
                update(2 * node + 2, mid + 1, end, index, val);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int sumRange(int left, int right) {
        return query(0, 0, nums.size() - 1, left, right);
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) 
            return 0;
        if (left <= start && right >= end) 
            return tree[node];
        int mid = start + (end - start) / 2;
        int leftSum = query(2 * node + 1, start, mid, left, right);
        int rightSum = query(2 * node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    
    cout << "Initial sum of range [0, 2]: " << numArray.sumRange(0, 2) << endl;  // Output: 9
    
    numArray.update(1, 2);
    
    cout << "Updated sum of range [0, 2]: " << numArray.sumRange(0, 2) << endl;  // Output: 8
    
    return 0;
}
