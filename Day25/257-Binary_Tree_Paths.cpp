#include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.

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
    void helper(TreeNode* root, vector<string>& ans, string str) {
        if (!root) return;
        
        if (root->left || root->right)
            str += to_string(root->val) + "->";
        else
            ans.push_back(str += to_string(root->val));
        
        helper(root->left, ans, str);
        helper(root->right, ans, str);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = "";
        
        helper(root, ans, str);
        
        return ans;
    }
};

int main() {
    // Example to test the binaryTreePaths function.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);

    // Print the result
    for (const string& path : result) {
        cout << path << endl;
    }

    // Clean up allocated memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
