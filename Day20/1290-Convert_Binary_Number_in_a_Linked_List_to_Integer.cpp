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
    int length(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        
        while(temp) {
            len++;
            temp = temp->next;
        }
        
        return len;
    }
    
    int getDecimalValue(ListNode* head) {
        if(head == nullptr)
            return 0;
        
        if(head->next == nullptr)
            return head->val ? 1 : 0;
        
        int len = length(head);
        int powOfTwo = pow(2, len - 1);
        int ans = 0;
        ListNode* temp = head;
        
        while(temp) {
            ans += powOfTwo * temp->val;
            temp = temp->next;
            powOfTwo /= 2;
        }
        
        return ans;
    }
};

int main() {
    // Create a linked list 1 -> 0 -> 1
    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(0, node3);
    ListNode* node1 = new ListNode(1, node2);
    
    // Create Solution object
    Solution sol;
    
    // Get the decimal value of the linked list
    int result = sol.getDecimalValue(node1);
    
    // Print the result
    cout << "Decimal value of the linked list: " << result << endl;
    
    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    
    return 0;
}
