#include <bits/stdc++.h>
using namespace std;

// Structure definition for Node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Class definition for Solution
class Solution {
private:
    void solve(Node* root, int k, vector<int> &path, int &count) {
        if (root == nullptr) {
            return;
        }
        
        // Add current node to path
        path.push_back(root->data);
        
        // Check all sub-paths ending at this node
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i]; // Update sum
            if (sum == k) {
                count++;
            }
        }
        
        // Recur for left and right subtrees
        solve(root->left, k, path, count);
        solve(root->right, k, path, count);
        
        // Backtrack: Remove current node from path
        path.pop_back();
    }
    
public:
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0; // Initialize count to 0
        
        solve(root, k, path, count);
        
        return count;
    }
};

// Main function to test the solution
int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(1);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    Solution sol;
    int k = 5;
    cout << "Number of paths with sum " << k << " is: " << sol.sumK(root, k) << endl;

    return 0;
}
