#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        
        if ((p->val >= root->val && q->val <= root->val) || (p->val <= root->val && q->val >= root->val))
            return root;
        
        if (p->val >= root->val && q->val >= root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return lowestCommonAncestor(root->left, p, q);
    }
};

int main() {
    Solution sol;
    
    // Example tree construction
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    
    // Example nodes for p and q
    TreeNode* p = root->left;        // Node with value 2
    TreeNode* q = root->left->right; // Node with value 4
    
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "No Common Ancestor Found" << endl;
    }
    
    // Freeing up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
