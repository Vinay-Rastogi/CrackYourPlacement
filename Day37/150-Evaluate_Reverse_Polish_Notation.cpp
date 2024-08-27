#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calc(int a, int b, char sign)
    {

        switch (sign)
        {

        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;
        }

        return -1;
    }

    int evalRPN(vector<string> &tokens)
    {

        stack<int> nums;
        int result;

        if (tokens.size() == 1)
        {
            return stoi(tokens[0]);
        }

        for (auto &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                if (nums.size() >= 2)
                {
                    int operand2 = nums.top();
                    nums.pop();
                    int operand1 = nums.top();
                    nums.pop();
                    char sign = token[0];
                    result = calc(operand1, operand2, sign);
                    nums.push(result);
                    cout << operand1 << sign << operand2 << "\n";
                }
            }
            else
            {
                nums.push(stoi(token));
            }
        }

        return result;
    }
};

int main()
{
    Solution sl;
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    cout << sl.evalRPN(tokens);

    return 0;
}