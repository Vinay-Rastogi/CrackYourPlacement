#include <bits/stdc++.h>
using namespace std;

/* BST Node */
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* temp = root;
        Node* pred = NULL;
        Node* succ = NULL;
        
        // Finding the node with the given key
        while(temp != NULL && temp->key != key)
        {
            if(temp->key > key)
            {
                succ = temp;
                temp = temp->left;
            }
            else
            {
                pred = temp;
                temp = temp->right;
            }
        }
        
        // If the node with the key is found
        if(temp != NULL)
        {
            // Finding the predecessor
            Node* lefttree = temp->left;
            while(lefttree != NULL)
            {
                pred = lefttree;
                lefttree = lefttree->right;
            }
            
            // Finding the successor
            Node* righttree = temp->right;
            while(righttree != NULL)
            {
                succ = righttree;
                righttree = righttree->left;
            }
        }
        
        pre = pred;
        suc = succ;
    }
};

int main()
{
    // Example usage
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    Solution sol;
    Node* pre = NULL;
    Node* suc = NULL;
    int key = 65;
    sol.findPreSuc(root, pre, suc, key);

    if(pre != NULL)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor" << endl;

    if(suc != NULL)
        cout << "Successor is " << suc->key << endl;
    else
        cout << "No Successor" << endl;

    return 0;
}
