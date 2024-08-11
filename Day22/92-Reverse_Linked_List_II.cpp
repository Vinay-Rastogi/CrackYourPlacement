#include <iostream>
#include<bits/stdc++.h>


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
    ListNode* reverse(ListNode* head) {
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* current = head;
        ListNode* prev = NULL;
        int count = 1;

        while (count < left) {
            prev = current;
            current = current->next;
            count++;
        }
        
        ListNode* start = current;
        ListNode* end = NULL;
        while (count <= right) {
            end = current;
            current = current->next;
            count++;
        }
        
        ListNode* rest = current;
        end->next = NULL;
        
        ListNode* newHead = reverse(start);
        
        if (prev != NULL) {
            prev->next = newHead;
        }
        else {
            head = newHead;
        }
        
        start->next = rest;
        
        return head;
    }
};

// Example usage
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    // Reverse between positions 2 and 4: expected result is 1 -> 4 -> 3 -> 2 -> 5
    head = sol.reverseBetween(head, 2, 4);

    // Print the result
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
