#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int maxLen = 0;
        for(int i = 0; i < str1.length(); i++) {
            for(int j = 1; j <= str1.length() - i; j++) {
                if(str2.find(str1.substr(i, j)) != -1) {
                    if(j > maxLen) maxLen = j;
                } else break;
            }
        }
        return maxLen;
    }
};

int main() {
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";
    
    Solution solution;
    int result = solution.longestCommonSubstr(str1, str2);
    
    cout << "The length of the longest common substring is: " << result << endl;

    return 0;
}
