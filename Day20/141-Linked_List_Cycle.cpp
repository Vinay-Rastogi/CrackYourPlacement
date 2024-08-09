#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
                return true;
        }
        
        return false;
    }
};

int main() {
    // Create a cycle for testing
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    
    Solution solution;
    bool result = solution.hasCycle(head);
    
    if (result) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Free the allocated memory (Note: Since there's a cycle, we'll break it before freeing)
    node4->next = NULL;
    delete node4;
    delete node3;
    delete node2;
    delete head;

    return 0;
}
