#include <bits/stdc++.h>
using namespace std;

class twoStacks {
    int* arr;
    int size;
    int top1;
    int top2;

public:
    twoStacks(int size = 100) {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1; // Return -1 if stack1 is empty
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1; // Return -1 if stack2 is empty
        }
    }
};

int main() {
    // Creating an object of twoStacks with a size of 10
    twoStacks ts(10);

    // Pushing elements into stack1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Pushing elements into stack2
    ts.push2(20);
    ts.push2(25);
    ts.push2(30);

    // Popping elements from stack1
    cout << "Popped element from stack1: " << ts.pop1() << endl; // 15
    cout << "Popped element from stack1: " << ts.pop1() << endl; // 10
    cout << "Popped element from stack1: " << ts.pop1() << endl; // 5
    cout << "Popped element from stack1: " << ts.pop1() << endl; // -1 (stack1 is empty)

    // Popping elements from stack2
    cout << "Popped element from stack2: " << ts.pop2() << endl; // 30
    cout << "Popped element from stack2: " << ts.pop2() << endl; // 25
    cout << "Popped element from stack2: " << ts.pop2() << endl; // 20
    cout << "Popped element from stack2: " << ts.pop2() << endl; // -1 (stack2 is empty)

    return 0;
}
