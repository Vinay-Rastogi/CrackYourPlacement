
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
    void rearrangeEvenOdd(Node* head) {
        Node* dummy1 = new Node(0);
        Node* oddNodeHead = dummy1;
        Node* dummy2 = new Node(0);
        Node* evenNodeHead = dummy2;
        bool isEven = false;
        
        while (head != NULL) {
            if (isEven) {
                dummy2->next = head;
                dummy2 = dummy2->next;
            } else {
                dummy1->next = head;
                dummy1 = dummy1->next;
            }
            head = head->next;
            isEven = !isEven;
        }
        
        dummy1->next = evenNodeHead->next;
        dummy2->next = NULL;
        head = oddNodeHead->next;
    }
};

// Function to print linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
   

    Solution obj;
    obj.rearrangeEvenOdd(head);

    printList(head);  // Expected Output: 1 3 5 2 4

    return 0;
}
