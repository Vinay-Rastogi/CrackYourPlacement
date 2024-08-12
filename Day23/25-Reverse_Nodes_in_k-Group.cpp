#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* currCheck = head;
        for(int i = 0; i < k; i++) {
            if(currCheck == NULL)
                return head;
            currCheck = currCheck->next;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        for(int i = 0; i < k; i++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(vals);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(reversedHead);

    return 0;
}
