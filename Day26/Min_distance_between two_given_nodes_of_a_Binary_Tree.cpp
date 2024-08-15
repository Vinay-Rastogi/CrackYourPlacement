#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = 0;
    
    int f(Node* root, int a, int b, int i = 0) {
        if (root == NULL) return 0;
        
        int l = f(root->left, a, b, i + 1);
        int r = f(root->right, a, b, i + 1);
        
        if ((root->data == a || root->data == b) && (l || r)) {
            ans = abs((max(l, r) - i));
            return (max(l, r) - i);
        }
        
        if (l && r) {
            ans = abs(l + r - 2 * i);
            return ans;
        }
        
        if (max(l, r)) return max(l, r);
        
        if (root->data == a || root->data == b) return i;
        return 0;
    }
    
    int findDist(Node* root, int a, int b) {
        f(root, a, b);
        return ans;
    }
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Sample binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution sol;
    int a = 4, b = 5;
    cout << "The minimum distance between " << a << " and " << b << " is: " << sol.findDist(root, a, b) << endl;

    return 0;
}
