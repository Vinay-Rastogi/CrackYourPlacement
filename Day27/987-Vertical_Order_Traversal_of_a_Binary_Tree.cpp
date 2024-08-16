#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> ans;
        if(!root) return ans;

        queue<pair<TreeNode *,pair<int,int>>> q; 
        map<int, map<int,vector<int>>> mp;

        int level = 0;
        q.push({root,{0,level}});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto top = q.front();
                q.pop();
                TreeNode *node = top.first;
                int line = top.second.first;

                mp[line][level].push_back(node->val);

                if(node->left)
                    q.push({node->left,{line-1,level}});
                if(node->right)
                    q.push({node->right,{line+1,level}});
            }
            level++;
        }
        for (auto it : mp) {
            vector<int> temp;
            for (auto x : it.second) {
                sort(x.second.begin(), x.second.end());
                for (int i : x.second) temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Creating a Solution object
    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Printing the result
    for (auto vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Freeing allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
