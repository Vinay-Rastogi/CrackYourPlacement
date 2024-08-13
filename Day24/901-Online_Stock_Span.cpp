#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int span = 0;

    StockSpanner() {}

    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if (!st.empty()) {
            int res = span - st.top().second;
            st.push({price, span});
            span++;
            return res;
        }

        st.push({price, span});
        span++;
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    cout << obj->next(100) << endl; // Output: 1
    cout << obj->next(80) << endl;  // Output: 1
    cout << obj->next(60) << endl;  // Output: 1
    cout << obj->next(70) << endl;  // Output: 2
    cout << obj->next(60) << endl;  // Output: 1
    cout << obj->next(75) << endl;  // Output: 4
    cout << obj->next(85) << endl;  // Output: 6

    delete obj;
    return 0;
}
