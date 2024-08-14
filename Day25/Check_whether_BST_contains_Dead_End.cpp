#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

class Solution {
  public:
    bool helper(Node* root, set<int>& st) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            if (st.find(root->data - 1) != st.end() && st.find(root->data + 1) != st.end()) 
                return true;
        }
        st.insert(root->data);
        return helper(root->left, st) || helper(root->right, st);
    }

    bool isDeadEnd(Node* root) {
        set<int> st;
        st.insert(0);
        return helper(root, st);
    }
};

int main() {
    // Sample tree creation
    Node* root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(11);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->left->left->left = newNode(1);
    
    Solution sol;
    if (sol.isDeadEnd(root)) {
        cout << "The tree has a dead end." << endl;
    } else {
        cout << "The tree does not have a dead end." << endl;
    }

    return 0;
}
