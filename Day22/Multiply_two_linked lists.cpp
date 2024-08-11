#include <iostream>
using namespace std;

/* Linked list node structure */
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class solution {
public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1 = 0, num2 = 0;
        long long mod = 1000000007;
        Node* temp1 = first;
        Node* temp2 = second;
        while (temp1) {
            num1 = (num1 * 10) % mod + (temp1->data) % mod;
            temp1 = temp1->next;
        }
        while (temp2) {
            num2 = (num2 * 10) % mod + (temp2->data) % mod;
            temp2 = temp2->next;
        }
        long long ans = (num1 * num2) % mod;
        return ans % mod;
    }
};

// Utility function to create a new Node
Node* newNode(int data) {
    Node* temp = new Node(data);
    return temp;
}

int main() {
    // Creating first linked list: 123
    Node* first = newNode(3);
    first->next = newNode(2);
    

    // Creating second linked list: 456
    Node* second = newNode(2);

    solution sol;
    cout << "Product of linked lists: " << sol.multiplyTwoLists(first, second) << endl;

    return 0;
}
