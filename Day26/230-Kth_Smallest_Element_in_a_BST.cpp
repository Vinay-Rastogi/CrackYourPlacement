#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
     
    vector<int> in;
    
    void inOrder(TreeNode* root){
        
        if(root == NULL)
            return ;
        
        inOrder(root->left);
         in.push_back(root->val);
        inOrder(root->right);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
          inOrder(root);
        
        return in[k-1];
    }
};
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    Solution solution;
    int k = 1; // Example value of k
    cout << "The " << k << "th smallest element is: " << solution.kthSmallest(root, k) << endl;

    // Cleanup
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
