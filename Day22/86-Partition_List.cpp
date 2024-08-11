#include <iostream>
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* LStart = NULL;
        ListNode* LEnd = NULL;
        ListNode* GStart = NULL;
        ListNode* GEnd = NULL;
        
        ListNode* temp = head;
        
        while (temp) {
            if (temp->val < x) {
                if (LStart == NULL) {
                    LStart = temp;
                    LEnd = temp;
                } else {
                    LEnd->next = temp;
                    LEnd = LEnd->next;
                }
            } else {
                if (GStart == NULL) {
                    GStart = temp;
                    GEnd = temp;
                } else {
                    GEnd->next = temp;
                    GEnd = GEnd->next;
                }
            }
            
            temp = temp->next;
        }
        
        if (LStart == NULL || GStart == NULL) {
            return head;
        }
        
        LEnd->next = GStart;
        GEnd->next = NULL;
        
        return LStart;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 4, 3, 2, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);
    
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    int x = 3;
    ListNode* newHead = sol.partition(head, x);
    
    cout << "Partitioned List: ";
    printList(newHead);
    
    // Cleanup
    while (newHead != NULL) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }
    
    return 0;
}
