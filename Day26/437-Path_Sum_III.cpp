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
private:
    int ans = 0;

    void helper(TreeNode* root, double sum) {
        if (root == nullptr) 
            return;

        if (sum == root->val)
            ans++;

        sum = sum - root->val;

        helper(root->left, sum);
        helper(root->right, sum);
    }

public:    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;

        helper(root, targetSum * 1.0);

        pathSum(root->left, targetSum * 1.0); 
        pathSum(root->right, targetSum * 1.0);

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 8;
    int result = sol.pathSum(root, targetSum);
    
    cout << "Number of paths that sum to " << targetSum << ": " << result << endl;

    // Free allocated memory
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->right->right;
    delete root->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
