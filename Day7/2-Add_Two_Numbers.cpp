#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode(0);
        ListNode* AnsHead = Head;
        int carry = 0;

        while (l1 && l2) {
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            Head->next = new ListNode(value % 10);
            Head = Head->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int value = l1->val + carry;
            carry = value / 10;
            Head->next = new ListNode(value % 10);
            Head = Head->next;
            l1 = l1->next;
        }

        while (l2) {
            int value = l2->val + carry;
            carry = value / 10;
            Head->next = new ListNode(value % 10);
            Head = Head->next;
            l2 = l2->next;
        }

        if (carry) {
            Head->next = new ListNode(carry);
        }

        return AnsHead->next;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& nums) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return head->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << " -> ";
    }
    cout << endl;
}

int main() {
    // Create two linked lists representing the numbers 342 and 465
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    // Add the two numbers
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printList(result);

    // Clean up allocated memory
    while (l1) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
