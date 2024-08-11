#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *previous = &dummy;
        ListNode *current = head;

        while (current)
        {
            ListNode *next_node = current->next;

            while (next_node && current->val == next_node->val)
            {
                ListNode *temp = next_node->next;
                delete next_node;
                next_node = temp;
            }

            if (current->next == next_node)
            {
                previous = current;
            }
            else
            {
                previous->next = next_node;
                delete current;
            }

            current = next_node;
        }

        return dummy.next;
    }
};

int main()
{
    // Example usage
    ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    Solution sol;
    ListNode *newHead = sol.deleteDuplicates(head);

    // Print the list
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}
