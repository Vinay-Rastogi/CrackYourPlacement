#include <bits/stdc++.h>
using namespace std;

class Node {
public:    
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;

        if (root->left != NULL)
            root->left->next = root->right;

        if (root->right != NULL && root->next != NULL)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};

void printTree(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* node = q.front();
            q.pop();

            cout << node->val << " ";
            if (node->next) cout << "(next: " << node->next->val << ") ";
            else cout << "(next: NULL) ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    // Creating a simple binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    // Printing the tree levels with next pointers
    printTree(root);

    return 0;
}
