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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<vector<int>> Res;

        if(root == NULL)
            return Res;

        st1.push(root);

        while(!st1.empty() || !st2.empty()) {
            vector<int> tem;

            while(!st1.empty()) {
                TreeNode* temp = st1.top();
                st1.pop();
                tem.push_back(temp->val);

                if(temp->left != NULL)
                    st2.push(temp->left);

                if(temp->right != NULL)
                    st2.push(temp->right);
            }

            if(!tem.empty()) {
                Res.push_back(tem);
                tem.clear();
            }

            while(!st2.empty()) {
                TreeNode* temp = st2.top();
                st2.pop();
                tem.push_back(temp->val);

                if(temp->right != NULL)
                    st1.push(temp->right);

                if(temp->left != NULL)
                    st1.push(temp->left);
            }

            if(!tem.empty())
                Res.push_back(tem);
        }

        return Res;
    }
};

// Example usage
int main() {
    // Create a simple tree for demonstration
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Cleanup
    // (In a real application, you should delete the nodes to avoid memory leaks)
    return 0;
}
