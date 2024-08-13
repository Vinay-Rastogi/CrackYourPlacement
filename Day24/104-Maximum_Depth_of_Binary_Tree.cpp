#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else {
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
            return max(lDepth, rDepth) + 1;
        }
    }
};

int main() {
    // Construct a sample tree:
    //       3
    //      / \
    //     9  20
    //        / \
    //       15  7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Maximum depth of the binary tree is: " << depth << endl; // Output should be 3

    // Clean up memory
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
