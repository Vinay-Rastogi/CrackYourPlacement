#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;

        // Extract values from the linked list into the vector
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the vector
        sort(v.begin(), v.end());

        // Reassign sorted values back to the linked list
        temp = head;
        for (auto x : v) {
            temp->val = x;
            temp = temp->next;
        }

        return head;
    }
};

// Helper function to create a new node
ListNode* createNode(int value) {
    return new ListNode(value);
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    cout << "Original List: ";
    printList(head);

    // Sort the list
    Solution sol;
    ListNode* sortedHead = sol.sortList(head);

    cout << "Sorted List: ";
    printList(sortedHead);

    return 0;
}
