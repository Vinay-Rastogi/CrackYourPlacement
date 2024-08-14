#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = INT_MAX;
    int num = -1;

    int getMinimumDifference(TreeNode* root) {
        if (root->left != nullptr)
            getMinimumDifference(root->left);

        if (num >= 0)
            ans = min(ans, root->val - num);

        num = root->val;

        if (root->right != nullptr)
            getMinimumDifference(root->right);

        return ans;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int result = sol.getMinimumDifference(root);
    cout << "Minimum difference: " << result << endl;

    // Free the allocated memory (not necessary for this example but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
