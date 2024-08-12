#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int res = s1.top();
        s1.pop();
        return res;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(10);
    obj->push(20);
    cout << "Peek: " << obj->peek() << endl;  // Output: 10
    cout << "Pop: " << obj->pop() << endl;    // Output: 10
    cout << "Peek: " << obj->peek() << endl;  // Output: 20
    cout << "Is Empty: " << (obj->empty() ? "Yes" : "No") << endl;  // Output: No
    obj->pop(); 
    cout << "Is Empty: " << (obj->empty() ? "Yes" : "No") << endl;  // Output: Yes

    delete obj;
    return 0;
}
