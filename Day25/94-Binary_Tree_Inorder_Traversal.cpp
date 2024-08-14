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
    vector<int> help(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return v;
        }
        help(root->left, v);
        v.push_back(root->val);
        help(root->right, v);
        return v;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Res;
        return help(root, Res);
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Printing the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
