#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> map; // val: {index in arr}

    RandomizedCollection() {}

    bool insert(int val) {
        arr.push_back(val);
        map[val].insert(arr.size() - 1);
        return map[val].size() <= 1;
    }

    bool remove(int val) {
        if (map[val].size() == 0)
            return false;
        int ind = *map[val].begin();
        map[val].erase(ind);

        int num = arr.back();
        swap(arr[ind], arr[arr.size() - 1]);
        map[num].insert(ind);
        map[num].erase(arr.size() - 1);
        arr.pop_back();
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

int main() {
    // Create a RandomizedCollection object
    RandomizedCollection* obj = new RandomizedCollection();
    
    // Insert values
    cout << "Insert 1: " << (obj->insert(1) ? "true" : "false") << endl; // Expected true
    cout << "Insert 1: " << (obj->insert(1) ? "true" : "false") << endl; // Expected false
    cout << "Insert 2: " << (obj->insert(2) ? "true" : "false") << endl; // Expected true
    
    // Remove values
    cout << "Remove 1: " << (obj->remove(1) ? "true" : "false") << endl; // Expected true
    cout << "Remove 1: " << (obj->remove(1) ? "true" : "false") << endl; // Expected true
    cout << "Remove 1: " << (obj->remove(1) ? "true" : "false") << endl; // Expected false
    
    // Get random values
    cout << "Random element: " << obj->getRandom() << endl;
    cout << "Random element: " << obj->getRandom() << endl;

    // Clean up
    delete obj;
    return 0;
}
