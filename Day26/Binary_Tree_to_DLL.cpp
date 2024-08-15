#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// This function should return head to the DLL
class Solution {
  public:
    void solve(Node *root, vector<int> &arr) {
        if (!root)
            return;
        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }

    Node *bToDLL(Node *root) {
        vector<int> arr;
        solve(root, arr);
        if (arr.empty())
            return NULL;
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); i++) {
            Node *temp = new Node(arr[i]);
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
        return head;
    }
};

int main() {
    // Example usage:
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    Solution sol;
    Node *head = sol.bToDLL(root);

    // Printing the Doubly Linked List
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;

    return 0;
}
