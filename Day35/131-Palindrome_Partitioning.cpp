#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalin(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(int index, string s, vector<string>& path, vector<vector<string>>& res) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalin(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                helper(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;
        helper(0, s, path, res);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    
    vector<vector<string>> result = sol.partition(s);

    cout << "Possible palindrome partitions of the string \"" << s << "\":" << endl;
    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
