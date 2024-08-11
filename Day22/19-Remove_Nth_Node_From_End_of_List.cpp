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
    int len(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = len(head);
        if (length == 1) {
            return NULL;
        }
        
        if (length == n) {
            return head->next;
        }
        
        ListNode* end = head;
        int e = length - n;
        while (e-1 && end) {
            e--;
            end = end->next;
        }
        
        ListNode* nextNode = end->next;
        end->next = end->next->next;
        delete nextNode;

        return head;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a list from an array
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

// Main function to test the removeNthFromEnd function
int main() {
    Solution solution;
    
    // Create a test list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    
    cout << "Original list: ";
    printList(head);
    
    int n = 2; // Remove the 2nd node from the end (should remove 4)
    head = solution.removeNthFromEnd(head, n);
    
    cout << "List after removing the " << n << "th node from the end: ";
    printList(head);
    
    // Cleanup memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
