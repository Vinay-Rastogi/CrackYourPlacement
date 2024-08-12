#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:
    // Function to merge two sorted linked lists
    Node* merge2Lists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        Node* head = l1->data <= l2->data ? l1 : l2;
        head->bottom = l1->data <= l2->data ? 
                      merge2Lists(l1->bottom, l2) : merge2Lists(l1, l2->bottom);
        return head;
    }

    // Function to flatten the linked list
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;
        return merge2Lists(root, flatten(root->next));
    }
};

// Helper function to print the flattened linked list
void printList(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

int main() {
    // Creating the linked list
    Node* root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);

    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next->bottom = new Node(20);

    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* flatRoot = sol.flatten(root);

    // Printing the flattened list
    printList(flatRoot);

    return 0;
}
