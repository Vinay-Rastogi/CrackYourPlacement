#include <iostream>
#include <bits/stdc++.h>

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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* temp = head;
        vector<int> copy;

        while (temp != nullptr) {
            copy.push_back(temp->val);
            temp = temp->next;
        }

        int low = 0;
        int high = copy.size() - 1;

        while (low < high) {
            if (copy[low] != copy[high])
                return false;
            low++;
            high--;
        }

        return true;
    }
};

int main() {
    // Creating a linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Freeing allocated memory
    ListNode* current = head;
    ListNode* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
