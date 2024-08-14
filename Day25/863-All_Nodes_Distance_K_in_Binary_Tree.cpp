#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        // Build parent map and level-order traversal of the tree
        while (!q.empty()) {
            int si = q.size();
            for (int i = 0; i < si; i++) {
                auto top = q.front();
                q.pop();
                
                if (top->left) {
                    parent[top->left->val] = top;
                    q.push(top->left); 
                }

                if (top->right) {
                    parent[top->right->val] = top;
                    q.push(top->right); 
                }
            }
        }

        unordered_map<int, int> visited;
        q.push(target);
        while (k-- && !q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();

                visited[top->val] = 1;

                if (top->left && !visited[top->left->val]) {
                    q.push(top->left);
                }

                if (top->right && !visited[top->right->val]) {
                    q.push(top->right);
                }

                if (parent[top->val] && !visited[parent[top->val]->val]) {
                    q.push(parent[top->val]);
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main() {
    // Create a sample tree: 
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // Node with value 5

    Solution solution;
    vector<int> result = solution.distanceK(root, target, 2);

    cout << "Nodes at distance 2 from target: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup memory (optional in competitive programming)
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
