#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> um;

        for (auto z : string_list) {
            string p = z;
            sort(p.begin(), p.end());
            um[p].push_back(z);
        }

        vector<vector<string>> ans;

        for (auto cc : um) {
            ans.push_back(cc.second);
        }

        return ans;
    }
};

int main() {
    Solution sl;

    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> result = sl.Anagrams(words);

    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
