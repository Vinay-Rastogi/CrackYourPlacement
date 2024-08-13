#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public: 
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode) {
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int ans = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

int main() {
    LRUCache* lruCache = new LRUCache(2); // Initialize LRUCache with a capacity of 2

    lruCache->put(1, 1); // Cache is {1=1}
    lruCache->put(2, 2); // Cache is {1=1, 2=2}

    cout << lruCache->get(1) << endl; // Returns 1

    lruCache->put(3, 3); // Cache is {1=1, 3=3}, removes key 2

    cout << lruCache->get(2) << endl; // Returns -1 (not found)

    lruCache->put(4, 4); // Cache is {4=4, 3=3}, removes key 1

    cout << lruCache->get(1) << endl; // Returns -1 (not found)
    cout << lruCache->get(3) << endl; // Returns 3
    cout << lruCache->get(4) << endl; // Returns 4

    return 0;
}
