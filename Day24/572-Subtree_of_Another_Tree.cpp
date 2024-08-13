#include <bits/stdc++.h>

using namespace std;

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
    bool issame(TreeNode *r1, TreeNode *r2) {
        if (r1 == nullptr && r2 == nullptr) return true;
        if (r1 == nullptr || r2 == nullptr) return false;
        if (r1->val != r2->val) return false;
        return issame(r1->left, r2->left) && issame(r1->right, r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;
        if (issame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    Solution sol;

    // Example tree setup
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    // Check if subRoot is a subtree of root
    bool result = sol.isSubtree(root, subRoot);
    cout << (result ? "Subtree found" : "Subtree not found") << endl;

    // Clean up memory (if using a tree-building utility, consider smart pointers)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    delete subRoot->left;
    delete subRoot->right;
    delete subRoot;

    return 0;
}
