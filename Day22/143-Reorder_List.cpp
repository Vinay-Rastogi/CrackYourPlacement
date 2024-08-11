#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode *fast = head, *slow = head, *prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = reverseList(slow);
        slow = prev->next;
        prev->next = NULL;

        ListNode *curr = head;
        int flag = 1;
        head = head->next;

        while (head && slow) {
            if (flag == 0) {
                curr->next = head;
                head = head->next;
                curr = curr->next;
                flag = 1;
            } else {
                curr->next = slow;
                slow = slow->next;
                curr = curr->next;
                flag = 0;
            }
        }
        if (slow != NULL)
            curr->next = slow;

        if (head != NULL)
            curr->next = head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from an array
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
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Reorder the list
    Solution sol;
    sol.reorderList(head);

    // Print reordered list
    cout << "Reordered list: ";
    printList(head);

    // Free the allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
