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
    bool CheckSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum - root->val == 0;
        }   
        
        return CheckSum(root->left, targetSum - root->val) || CheckSum(root->right, targetSum - root->val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return CheckSum(root, targetSum);
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    
    Solution solution;
    int targetSum = 22;
    
    if (solution.hasPathSum(root, targetSum)) {
        cout << "Path with target sum found." << endl;
    } else {
        cout << "No path with target sum found." << endl;
    }

    // Free allocated memory
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
