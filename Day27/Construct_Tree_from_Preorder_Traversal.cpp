#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to build the binary tree
Node *build(int &i, int n, int pre[], char preLN[]) {
    if (i >= n) return NULL;
    
    Node *root = new Node();
    root->data = pre[i];
    
    // If the current node is a leaf node
    if (preLN[i] == 'L') return root;
    
    // Otherwise, recursively build the left and right subtrees
    i++;
    root->left = build(i, n, pre, preLN);
    i++;
    root->right = build(i, n, pre, preLN);
    
    return root;
}

// Function to construct the binary tree
Node *constructTree(int n, int pre[], char preLN[]) {
    int i = 0;
    Node *root = build(i, n, pre, preLN);
    return root;
}

// Function to print the inorder traversal of the tree
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n = 5;
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    
    Node *root = constructTree(n, pre, preLN);
    
    cout << "Inorder traversal of the constructed tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
