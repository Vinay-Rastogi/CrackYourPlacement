#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int rangeSum = 0;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (node->val >= L && node->val <= R)
                rangeSum += node->val;

            if (node->val > L && node->left)
                st.push(node->left);

            if (node->val < R && node->right)
                st.push(node->right);
        }
        return rangeSum;
    }
};

int main() {
    // Create a sample tree: 
    //         10
    //        /  \
    //       5   15
    //      / \    \
    //     3   7    18
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution sol;
    int L = 7, R = 15;
    int result = sol.rangeSumBST(root, L, R);

    cout << "Range Sum: " << result << endl;  // Output: 32

    return 0;
}
