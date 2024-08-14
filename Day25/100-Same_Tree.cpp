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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q)
            return (p == q);
        if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        return false;
    }
};

int main() {
    // Example usage:
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(tree1, tree2);
    cout << (result ? "The trees are the same." : "The trees are not the same.") << endl;

    // Clean up dynamically allocated memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;

    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
