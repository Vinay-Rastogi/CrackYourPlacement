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
    void invert(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = right;
            root->right = left;
            invert(root->left);
            invert(root->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        invert(root);
        return root;
    }
};

// Helper function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Print original tree
    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    // Invert the tree
    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    // Print inverted tree
    cout << "Inverted Tree: ";
    printTree(invertedRoot);
    cout << endl;

    return 0;
}
