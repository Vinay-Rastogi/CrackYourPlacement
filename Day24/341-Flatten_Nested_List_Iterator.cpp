#include <bits/stdc++.h>
using namespace std;

// This is a mock-up implementation of the NestedInteger class for testing.
class NestedInteger {
public:
    // Default constructor initializes an empty nested list.
    NestedInteger() {}

    // Constructor initializes a single integer.
    NestedInteger(int value) : is_integer(true), integer(value) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return is_integer;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer.
    // The result is undefined if this NestedInteger holds a nested list.
    int getInteger() const {
        return integer;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        is_integer = true;
        integer = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        is_integer = false;
        nested_list.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list.
    // The result is undefined if this NestedInteger holds a single integer.
    const vector<NestedInteger> &getList() const {
        return nested_list;
    }

private:
    bool is_integer = false;
    int integer = 0;
    vector<NestedInteger> nested_list;
};

class NestedIterator {
public:
    vector<int> res;
    int idx = 0;

    void helper(const vector<NestedInteger>& v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].isInteger())
                res.push_back(v[i].getInteger());
            else
                helper(v[i].getList());
        }
    }

    NestedIterator(vector<NestedInteger>& nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger())
                res.push_back(nestedList[i].getInteger());
            else
                helper(nestedList[i].getList());
        }
    }

    int next() {
        return res[idx++];
    }

    bool hasNext() {
        return idx < res.size();
    }
};

int main() {
    // Example nested list: [[1,1],2,[1,1]]
    NestedInteger ni1(1), ni2(2);
    NestedInteger list1, list2;

    list1.add(ni1);
    list1.add(ni1);

    list2.add(ni1);
    list2.add(ni1);

    vector<NestedInteger> nestedList = {list1, ni2, list2};

    NestedIterator i(nestedList);
    while (i.hasNext()) {
        cout << i.next() << " ";
    }
    cout << endl;

    return 0;
}