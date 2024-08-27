#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* zigZag(Node* head) {
        if (!head || !head->next)
            return head;
        Node* curr = head;
        bool flag = true;
        while (curr->next != NULL) {
            if (flag) {
                if (curr->data > curr->next->data) {
                    swap(curr->data, curr->next->data);
                }
            } else {
                if (curr->data < curr->next->data) {
                    swap(curr->data, curr->next->data);
                }
            }
            curr = curr->next;
            flag = !flag;
        }
        return head;
    }
};

// Utility function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Utility function to create a linked list from a vector of values
Node* createList(vector<int>& arr) {
    if (arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};
    Node* head = createList(arr);

    Solution obj;
    head = obj.zigZag(head);

    cout << "Zig-Zag Linked List: ";
    printList(head);

    return 0;
}
