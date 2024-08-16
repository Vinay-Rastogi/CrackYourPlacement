#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    int ans = 0;

    vector<int> solve(Node* root){
        if(!root)
            return {0, INT_MAX, INT_MIN};

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        if(l[0] >= 0 && r[0] >= 0){
            if(root->left && root->data <= l[2]){
                return {-1, -1, -1};
            }
            if(root->right && root->data >= r[1]){
                return {-1, -1, -1};
            }
            int mi = min(l[1], root->data);
            int mx = max(r[2], root->data);
            ans = max(ans, l[0] + r[0] + 1);
            return {l[0] + r[0] + 1, mi, mx};
        }
        return {-1, -1, -1};
    }
    
    int largestBst(Node *root) {
        solve(root);
        return ans;
    }
};

int main() {
    // Example usage:
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    Solution solution;
    cout << "Size of the largest BST is: " << solution.largestBst(root) << endl;

    return 0;
}
