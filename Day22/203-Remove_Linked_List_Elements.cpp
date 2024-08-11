#include <iostream>
#include<bits/stdc++.h>


using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;

        ListNode* temp = head;
        ListNode* pre = NULL;

        while (temp) {
            if (temp == head && head->val == val) {
                if (head->next == NULL)
                    return NULL;

                temp = head;
                head = head->next;

                delete temp;
                temp = head;
            }
            else if (temp->val == val && temp != head) {
                pre->next = temp->next;
                delete temp;
                temp = pre->next;
            }
            else {
                pre = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array of values
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage
    vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    int valToRemove = 6;

    ListNode* head = createList(values);
    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.removeElements(head, valToRemove);

    cout << "Modified list after removing " << valToRemove << ": ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
