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
    int maxLen = 0;
    
    int diameterOfBinaryTree(TreeNode* r) {
        return maxDown(r), maxLen;
    }
    
    int maxDown(TreeNode* x) {
        if (!x) 
            return 0;

        int maxL = maxDown(x->left);
        int maxR = maxDown(x->right);

        maxLen = max(maxLen, maxL + maxR);
        
        return max(maxL, maxR) + 1;        
    } 
};

int main() {
    // Example tree: [1, 2, 3, 4, 5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
