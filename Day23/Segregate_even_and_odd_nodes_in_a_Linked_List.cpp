#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Definition for singly-linked list. */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* divide(Node* head) {
        Node* dodd = new Node(-1);
        Node* oddtemp = dodd;
        Node* deven = new Node(-1);
        Node* eventemp = deven;
        Node* curr = head;
        Node* temp = NULL;
        while (curr) {
            if (curr->data % 2 == 0) {
                eventemp->next = curr;
                eventemp = eventemp->next;
            } else {
                oddtemp->next = curr;
                oddtemp = oddtemp->next;
            }
            temp = curr->next;
            curr->next = NULL;
            curr = temp;
        }
        eventemp->next = dodd->next;
        return deven->next;
    }
};

// Helper function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector of values
Node* createList(vector<int>& values) {
    if (values.empty()) return NULL;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage:
    vector<int> values = {17, 15, 8, 9, 2, 4, 6};
    Node* head = createList(values);

    Solution sol;
    Node* result = sol.divide(head);

    printList(result);

    return 0;
}
