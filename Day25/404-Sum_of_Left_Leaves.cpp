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
    
    int dfs(TreeNode* root, bool isLeft) {
        if(!root) 
            return 0;
         
        if(!root->left && !root->right) 
            return isLeft ? root->val : 0;
         
        return dfs(root->left, true) + dfs(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};

// Main function to test the code
int main() {
    // Create a sample tree: 
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    int result = sol.sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << result << endl; // Output should be 24 (9 + 15)
    
    return 0;
}
