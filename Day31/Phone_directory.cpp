#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool fun(string &a, string &b, int r) {
        while (r >= 0) {
            if (a[r] != b[r])
                return false;
            r--;
        }
        return true;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        sort(contact, contact + n);
        vector<vector<string>> ans;
        unordered_map<string, bool> chlega;

        for (int i = s.size() - 1; i >= 0; i--) {
            unordered_map<string, bool> visited;
            vector<string> temp;
            for (int j = 0; j < n; j++) {
                if (chlega[contact[j]] == true) {
                    if (!visited[contact[j]])
                        temp.push_back(contact[j]);
                    visited[contact[j]] = true;
                } else if (contact[j].size() > i) {
                    if (fun(s, contact[j], i)) {
                        if (!visited[contact[j]])
                            temp.push_back(contact[j]);
                        chlega[contact[j]] = true;
                        visited[contact[j]] = true;
                    }
                }
            }
            if (temp.size() == 0)
                temp.push_back("0");
            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n = 3;
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string s = "geeips";

    Solution sol;
    vector<vector<string>> result = sol.displayContacts(n, contact, s);

    for (const auto &v : result) {
        for (const auto &str : v) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
