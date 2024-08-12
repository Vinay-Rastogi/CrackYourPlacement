#include <bits/stdc++.h>
using namespace std;

void push_back_pb(deque<int> &dq, int x) {
    dq.push_back(x);
}

// Function to pop element from back of the deque.
void pop_back_ppb(deque<int> &dq) {
    if (!dq.empty())
        dq.pop_back();
    else 
        return;
}

// Function to return element from front of the deque.
int front_dq(deque<int> &dq) {
    if (!dq.empty())
        return dq.front();
    else 
        return -1;
}

// Function to push element x to the front of the deque.
void push_front_pf(deque<int> &dq, int x) {
    dq.push_front(x);
}

int main() {
    deque<int> dq;
    
    // Example usage of the functions
    push_back_pb(dq, 5);
    push_back_pb(dq, 10);
    push_front_pf(dq, 1);
    
    cout << "Front element: " << front_dq(dq) << endl; // Should print 1
    
    pop_back_ppb(dq);
    cout << "Front element after pop_back: " << front_dq(dq) << endl; // Should print 1

    pop_back_ppb(dq);
    cout << "Front element after another pop_back: " << front_dq(dq) << endl; // Should print 5
    
    return 0;
}
