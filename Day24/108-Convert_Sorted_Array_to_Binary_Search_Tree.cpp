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
    TreeNode* addtoBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = addtoBST(nums, left, mid - 1);
        root->right = addtoBST(nums, mid + 1, right);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return addtoBST(nums, 0, nums.size() - 1);
    }
};

// Helper function to print the tree in-order (for verification purposes)
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);
    
    // Print the tree in-order
    inorderTraversal(root);
    cout << endl;

    return 0;
}
