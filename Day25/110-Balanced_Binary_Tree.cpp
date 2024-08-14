#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* node) {
        if (node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    if (solution.isBalanced(root)) {
        cout << "The tree is balanced.\n";
    } else {
        cout << "The tree is not balanced.\n";
    }

    // Clean up memory
    delete root->left->left->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
