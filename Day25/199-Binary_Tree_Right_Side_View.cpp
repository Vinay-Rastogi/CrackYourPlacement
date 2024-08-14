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

    void helper(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL) return;

        // If we're at a new level, add the node's value
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Traverse the right subtree first
        helper(root->right, level + 1, ans);
        // Then traverse the left subtree
        helper(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        helper(root, 0, ans);
        return ans;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    
    Solution sol;
    vector<int> result = sol.rightSideView(root);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
