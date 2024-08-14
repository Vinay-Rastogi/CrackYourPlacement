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
    vector<TreeNode*> generateTrees(int n) {
        return n ? generate_trees(1, n) : vector<TreeNode*>();
    }

private:
    vector<TreeNode*> generate_trees(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> all_trees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = generate_trees(start, i - 1);
            vector<TreeNode*> right_trees = generate_trees(i + 1, end);

            for (TreeNode* l : left_trees) {
                for (TreeNode* r : right_trees) {
                    TreeNode* current_tree = new TreeNode(i);
                    current_tree->left = l;
                    current_tree->right = r;
                    all_trees.push_back(current_tree);
                }
            }
        }
        
        return all_trees;
    }
};

void printTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├── " : "└── ");
        cout << node->val << endl;
        printTree(node->left, prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

int main() {
    Solution sol;
    int n = 3; // Example input
    vector<TreeNode*> trees = sol.generateTrees(n);
    
    cout << "Number of unique BSTs generated: " << trees.size() << endl;

    // Print all generated trees
    for (int i = 0; i < trees.size(); ++i) {
        cout << "Tree " << i + 1 << ":" << endl;
        printTree(trees[i]);
        cout << endl;
    }
    
    return 0;
}
