#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Solution class
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hm;
        
        for (Node* curr = head; curr != NULL; curr = curr->next)
            hm[curr] = new Node(curr->val);
     
        for (Node* curr = head; curr != NULL; curr = curr->next) {
            Node* cloneCurr = hm[curr];
            cloneCurr->next = hm[curr->next];
            cloneCurr->random = hm[curr->random];
        }
        
        return hm[head];
    }
};

// Function to create the linked list from a vector of pairs
Node* createList(vector<pair<int, int>> nodes) {
    vector<Node*> nodeVec;
    for (auto& p : nodes) {
        nodeVec.push_back(new Node(p.first));
    }

    for (int i = 0; i < nodes.size(); ++i) {
        if (i < nodes.size() - 1) {
            nodeVec[i]->next = nodeVec[i + 1];
        }
        if (nodes[i].second != -1) {
            nodeVec[i]->random = nodeVec[nodes[i].second];
        }
    }

    return nodeVec[0];
}

// Function to print the list in the required format
void printList(Node* head) {
    Node* temp = head;
    vector<pair<int, int>> result;
    unordered_map<Node*, int> nodeMap;
    int index = 0;
    
    while (temp != NULL) {
        nodeMap[temp] = index++;
        temp = temp->next;
    }
    
    temp = head;
    while (temp != NULL) {
        int randomIndex = (temp->random) ? nodeMap[temp->random] : -1;
        result.push_back({temp->val, randomIndex});
        temp = temp->next;
    }
    
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[" << result[i].first << ",";
        if (result[i].second == -1)
            cout << "null";
        else
            cout << result[i].second;
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    // Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    vector<pair<int, int>> nodes = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    
    // Create the list from the vector of pairs
    Node* head = createList(nodes);

    // Print the original list
    cout << "Original list:" << endl;
    printList(head);

    // Copy the list using the solution
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    // Print the copied list
    cout << "Copied list:" << endl;
    printList(copiedList);

    // Clean up memory (both original and copied lists)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    while (copiedList != NULL) {
        temp = copiedList;
        copiedList = copiedList->next;
        delete temp;
    }

    return 0;
}
