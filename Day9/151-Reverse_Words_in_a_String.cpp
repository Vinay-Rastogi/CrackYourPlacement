#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        stack<string> st;
        string temp = "";

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] != ' ')
                temp += s[i];

            else if (s[i] == ' ')
            {
                if (temp.length() > 0)
                {
                    st.push(temp);
                    temp.clear();
                }
            }
        }

        if (temp.length() > 0)
            st.push(temp);

        temp.clear();

        int n = st.size() - 1;

        while (n)
        {

            temp += st.top() + " ";
            st.pop();
            n--;
        }

        temp += st.top();

        return temp;
    }
};

int main()
{
    Solution sl;
    string s = "the sky is blue";

    cout << sl.reverseWords(s);

    return 0;
}