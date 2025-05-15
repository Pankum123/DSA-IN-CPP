#include <iostream>
#include <stack>

using namespace std;

int findminimumcost(string str)
{

    // odd condition
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(')
            s.push(ch);
        else
        {
            // ch is closed brac
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '(')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}
int main()
{

    string str = "((()))((";
    int count = findminimumcost(str);

    if (count == -1)
    {
        cout << "not possible" << endl;
    }
    else
    {
        cout << "minimum cost valid = " << count << endl;
    }

    return 0;
}