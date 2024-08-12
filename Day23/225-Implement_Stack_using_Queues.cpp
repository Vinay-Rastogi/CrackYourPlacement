#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class MyStack {
public:
    queue<int> q1, q2;
    int size;

    MyStack() {
        size = 0;
    }

    void push(int x) {
        size++;
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop() {
        if (empty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
            return -1; // Assuming -1 as an error code for empty stack
        }
        size--;
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty. Cannot retrieve top element." << endl;
            return -1; // Assuming -1 as an error code for empty stack
        }
        return q1.front();
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    // Create a stack
    MyStack* obj = new MyStack();

    // Push elements
    obj->push(10);
    obj->push(20);
    obj->push(30);

    // Pop an element
    int param_2 = obj->pop();
    cout << "Popped: " << param_2 << endl;

    // Get top element
    int param_3 = obj->top();
    cout << "Top element: " << param_3 << endl;

    // Check if empty
    bool param_4 = obj->empty();
    cout << "Is empty: " << (param_4 ? "Yes" : "No") << endl;

    // Pop remaining elements
    obj->pop();
    obj->pop();

    // Try to pop from empty stack
    obj->pop();

    // Check if empty again
    param_4 = obj->empty();
    cout << "Is empty after popping all elements: " << (param_4 ? "Yes" : "No") << endl;

    // Clean up
    delete obj;

    return 0;
}
