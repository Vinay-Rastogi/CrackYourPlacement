#include <bits/stdc++.h>
using namespace std;

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode*, long>> q;
        int ans = 0;

        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long minm = q.front().second;
            int first, last;

            for (int i = 0; i < n; i++) {
                long cur_id = q.front().second - minm;
                TreeNode* temp = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_id;

                if (i == n - 1)
                    last = cur_id;

                if (temp->left)
                    q.push({temp->left, cur_id * 2 + 1});

                if (temp->right)
                    q.push({temp->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);
    cout << "Width of the binary tree is: " << result << endl;

    return 0;
}
