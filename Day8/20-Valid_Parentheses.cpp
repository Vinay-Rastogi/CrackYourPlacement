#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length() < 2)
            return false;
        
         int n=s.length();
        stack<char>stk;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                stk.push(s[i]);
            }
            else if(s[i]=='}'){
                
                if(!stk.empty() && stk.top()=='{'){
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
            else if(s[i]==']'){
              
                if(!stk.empty() && stk.top()=='['){
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
            else if(s[i]==')'){
              
                if(!stk.empty() && stk.top()=='('){
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
      
        return stk.size()==0;
    }
};

int main()
{

    Solution sl;
    string s = "()[]{}";

    cout << sl.isValid(s);

    return 0;
}