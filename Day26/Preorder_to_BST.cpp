#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// Function to create a new tree node
Node* newNode(int data) {
    return new Node(data);
}

// Solution class that contains the function to construct BST
class Solution {
public:
    // Helper function to construct BST from preorder traversal
    Node* f(int arr[], int size, int low, int up, int &index) {
        if (index == size || arr[index] < low || arr[index] > up) {
            return NULL;
        }
        Node *root = newNode(arr[index++]);
        root->left = f(arr, size, low, root->data, index);
        root->right = f(arr, size, root->data, up, index);
        return root;
    }

    // Function to construct BST from preorder traversal
    Node* Bst(int pre[], int size) {
        int index = 0;
        return f(pre, size, INT_MIN, INT_MAX, index);
    }
};

// Function to print inorder traversal of the BST (for verification)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);
    
    Node* root = sol.Bst(preorder, size);
    
    cout << "Inorder traversal of the constructed BST: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
