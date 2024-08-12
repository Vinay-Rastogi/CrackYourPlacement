#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

          stack<int> st;
          unordered_map<int,int> mp;
          vector<int> Res;

          for(int num : nums2) {
              while(!st.empty() && num > st.top()) {
                  mp[st.top()] = num;
                  st.pop();
              }
              st.push(num);
          }

          for(int num : nums1) {
              if(mp.find(num) == mp.end())
                  Res.push_back(-1);
              else
                  Res.push_back(mp[num]); 
          }

          return Res;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Result: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
