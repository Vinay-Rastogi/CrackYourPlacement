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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *unique = head;
        ListNode *nextNode = head->next;
        int prev_val = unique->val;

        while (nextNode) {
            if (prev_val != nextNode->val) {
                unique->next = nextNode;
                unique = unique->next;
                prev_val = nextNode->val;
            }
            nextNode = nextNode->next;
        }
        unique->next = nullptr;
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(result);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
