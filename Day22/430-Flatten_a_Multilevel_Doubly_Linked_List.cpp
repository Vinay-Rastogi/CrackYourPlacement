#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// Definition for a Node.
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head) {
            flatten_rec(head);
        }
        return head;
    }

private:
    Node* flatten_rec(Node* head) {
        Node* curr = head;
        Node* tail = head;
        
        while (curr) {
            Node* child = curr->child;
            Node* next = curr->next;
            
            if (child) {
                Node* _tail = flatten_rec(child);
                _tail->next = next;
                
                if (next) {
                    next->prev = _tail;
                }
                
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                curr = _tail;
            } else {
                curr = next;
            }
            
            if (curr) {
                tail = curr;
            }
        }
        
        return tail;
    }
};

int main() {
    // Example usage:
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->child = new Node(4);
    head->child->next = new Node(5);
    head->child->next->prev = head->child;
    head->child->next->child = new Node(6);
    
    Solution sol;
    Node* flattenedHead = sol.flatten(head);

    // Print the flattened list
    Node* curr = flattenedHead;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up
    curr = flattenedHead;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    
    return 0;
}
