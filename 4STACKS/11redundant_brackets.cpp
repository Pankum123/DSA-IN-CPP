#include <iostream>
#include <stack>

using namespace std;

bool findredundantbrackets(string str)
{

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            // ch ya ')' hai or lowercase letter
            if (ch == ')')
            {
                bool isredundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isredundant = false;
                    }
                    s.pop();
                }

                if (isredundant == true)
                    return true;
                s.pop();
            }
        }
    }
    return false;
}
int main()
{

    string str = "((a+b))";
    if (findredundantbrackets(str))
    {
        cout << "redundant";
    }
    else
    {
        cout << "not redundant";
    }

    return 0;
}