#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* build(vector<int>& pre, int preLow, int preHigh, vector<int>& post, int postLow, int postHigh) {
        // base case
        if(preLow > preHigh || postLow > postHigh) return NULL;
        
        TreeNode* root = new TreeNode(pre[preLow]);
        
        // when there is only one node
        if(preLow == preHigh) return root;
        
        int i = postLow;
        // find the 2nd element of preOrder in postOrder 
        while(i <= postHigh) {
            if(post[i] == pre[preLow + 1]) break;
            i++;
        }
        
        int leftCount = i - postLow;
        // recursion part of left & right subtree
        root->left = build(pre, preLow + 1, preLow + leftCount + 1, post, postLow, i);
        root->right = build(pre, preLow + leftCount + 2, preHigh, post, i + 1, postHigh);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};

int main() {
    Solution solution;
    
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    
    TreeNode* root = solution.constructFromPrePost(preorder, postorder);
    
    // Output the root value as a basic check
    cout << "Root Value: " << root->val << endl;
    
    return 0;
}
