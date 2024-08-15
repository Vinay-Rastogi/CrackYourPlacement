#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void solve(Node *root, int l, int h, int &count) {
        if (!root)
            return;
        solve(root->left, l, h, count);
        if (root->data >= l && root->data <= h) {
            count++;
        }
        solve(root->right, l, h, count);
    }
    
    int getCount(Node *root, int l, int h) {
        int count = 0;
        solve(root, l, h, count);
        return count;
    }
};

int main() {
    // Create a sample binary search tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    Solution sol;

    // Define the range
    int l = 6;
    int h = 15;

    // Get the count of nodes within the range [l, h]
    int count = sol.getCount(root, l, h);

    // Print the result
    cout << "Count of nodes within range [" << l << ", " << h << "] is: " << count << endl;

    // Clean up memory
    // This is a simple example, consider using smart pointers or a tree destructor in practice
    // For simplicity, we are not freeing the memory here

    return 0;
}
