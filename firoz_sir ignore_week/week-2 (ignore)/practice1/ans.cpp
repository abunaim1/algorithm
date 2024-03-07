#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // for others.
}

string infixToPostfix(const string &infix)
{
    stack<char> st;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix = postfix + c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        else
        {
            while (!st.empty() && st.top() != '(' &&
                   getPrecedence(c) <= getPrecedence(st.top()))
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infixExpression; cin >> infixExpression;

    cout << infixToPostfix(infixExpression) << endl;

    return 0;
}
