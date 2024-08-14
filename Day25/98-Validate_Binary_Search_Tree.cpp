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
    void inOrder(TreeNode* root) {
        if (root == NULL)
            return;

        inOrder(root->left);
        Ans.push_back(root->val);
        inOrder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        inOrder(root);

        for (int i = 0; i < Ans.size() - 1; i++)
            if (Ans[i] >= Ans[i + 1])
                return false;

        return true;
    }

private:
    vector<int> Ans;
};

int main() {
    // Sample usage: Create a tree and test the solution
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isValidBST(root) ? "true" : "false") << endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;

}