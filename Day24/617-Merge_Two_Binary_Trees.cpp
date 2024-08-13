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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL)
            return root2;

        if (root2 == NULL)
            return root1;

        TreeNode* temp = new TreeNode(root1->val + root2->val);

        if (root1->left != NULL || root2->left != NULL)
            temp->left = mergeTrees(root1->left, root2->left);

        if (root1->right != NULL || root2->right != NULL)
            temp->right = mergeTrees(root1->right, root2->right);

        return temp;
    }
};

// Helper function to print inorder traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Creating sample trees for demonstration
    TreeNode* root1 = new TreeNode(1, new TreeNode(3, new TreeNode(5), nullptr), new TreeNode(2));
    TreeNode* root2 = new TreeNode(2, new TreeNode(1, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(7)));

    Solution solution;
    TreeNode* mergedRoot = solution.mergeTrees(root1, root2);

    // Print inorder traversal of merged tree
    cout << "Inorder Traversal of Merged Tree: ";
    inorderTraversal(mergedRoot);
    cout << endl;

    return 0;
}
