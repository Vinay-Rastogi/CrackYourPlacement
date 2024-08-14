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

class BSTIterator {

    stack<TreeNode*> myStack;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* root) {
        for (; root != NULL; myStack.push(root), root = root->left);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    while (obj->hasNext()) {
        cout << obj->next() << " ";
    }
    cout << endl;

    // Clean up memory
    delete obj;
    // Assume a proper tree deletion function would be implemented here
    return 0;
}
