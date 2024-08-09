#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    
    void sort(Node **head)
    {
        if ((*head)->next == NULL)
            return;
        Node* p = NULL;
        Node* a = *head;
        Node* b = (*head)->next;
        while (b && b->next) {
            a->next = b->next;
            b->next = p;
            a = a->next;
            p = b;
            b = a->next;
        }
        if (b) {
            b->next = p;
        } 
        else
            a->next = p;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(2);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(3);

    // Printing original list
    cout << "Original Linked List: ";
    printList(head);

   
    Solution sol;
    sol.sort(&head);

    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}
