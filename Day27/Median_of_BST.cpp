#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to perform inorder traversal of the BST and store elements in a vector
void inorder(Node* root, vector<int>& v) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

// Function to find the median of the BST
float findMedian(Node* root) {
    vector<int> v;
    inorder(root, v);
    
    int n = v.size();
    
    if (n == 0) {
        return 0.0;
    }
    
    if (n % 2 == 1) {
        int x = n / 2;
        return v[x];
    } else {
        int x = n / 2;
        int y = x - 1;
        return (v[x] + v[y]) / 2.0;
    }
}

int main() {
    // Constructing the BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    // Finding the median of the BST
    float median = findMedian(root);
    cout << "The median of the BST is: " << median << endl;

    return 0;
}
