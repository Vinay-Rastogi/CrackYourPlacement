#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                st.push(S[i] - '0');
            }
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                switch (S[i])
                {
                case '+':
                    st.push(b + a);
                    break;

                case '-':
                    st.push(b - a);
                    break;

                case '*':
                    st.push(b * a);
                    break;

                case '/':
                    st.push(b / a);
                    break;
                }
            }
        }
        return st.top();
    }
};

int main()
{
    Solution sol;
    string expression = "231*+9-"; // Example postfix expression
    cout << "The result of the postfix expression " << expression << " is: " << sol.evaluatePostfix(expression) << endl;
    return 0;
}
