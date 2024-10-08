#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {

        string ans = "";

        while (num / 1000)
        {
            num -= 1000;
            ans += "M";
        }

        if (num / 900)
        {
            num -= 900;
            ans += "CM";
        }

        while (num / 500)
        {
            num -= 500;
            ans += "D";
        }

        if (num / 400)
        {
            num -= 400;
            ans += "CD";
        }

        while (num / 100)
        {
            num -= 100;
            ans += "C";
        }

        if (num / 90)
        {
            num -= 90;
            ans += "XC";
        }

        while (num / 50)
        {
            num -= 50;
            ans += "L";
        }

        if (num / 40)
        {
            num -= 40;
            ans += "XL";
        }

        while (num / 10)
        {
            num -= 10;
            ans += "X";
        }

        if (num / 9)
        {
            num -= 9;
            ans += "IX";
        }

        while (num / 5)
        {
            num -= 5;
            ans += "V";
        }

        if (num / 4)
        {
            num -= 4;
            ans += "IV";
        }

        while (num > 0)
        {
            num -= 1;
            ans += "I";
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    int num = 3749;

    cout << sl.intToRoman(num);

    return 0;
}