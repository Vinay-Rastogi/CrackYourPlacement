#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode *temp = headA;
        
        while (temp) {
            s.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while (temp) {
            if (s.find(temp) != s.end())
                return temp;
            temp = temp->next;
        }
        
        return NULL;
    }
};

// Helper function to create a linked list
ListNode* createList(vector<int> values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Creating two linked lists
    ListNode* list1 = createList({4, 1});
    ListNode* list2 = createList({5, 6, 1});
    
    // Creating an intersection node
    ListNode* intersection = new ListNode(8);
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);
    
    // Linking intersection to both lists
    list1->next->next = intersection;  // list1: 4 -> 1 -> 8 -> 4 -> 5
    list2->next->next->next = intersection;  // list2: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    
    // Testing getIntersectionNode function
    Solution solution;
    ListNode* result = solution.getIntersectionNode(list1, list2);
    
    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection." << endl;
    }
    
   
    delete list1->next->next->next; // delete 5
    delete list1->next->next->next->next; // delete 4
    delete intersection; // delete 8
    delete list1->next; // delete 1
    delete list1; // delete 4
    delete list2->next->next; // delete 1
    delete list2->next; // delete 6
    delete list2; // delete 5
    
    return 0;
}
