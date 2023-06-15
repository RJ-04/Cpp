#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

//------------------------------------------------------------------------------------

void insert_at_bottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int top_element = st.top();
    st.pop();
    insert_at_bottom(st, element);
    st.push(top_element);
}

void Reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int element = st.top();
    st.pop();
    Reverse(st);
    insert_at_bottom(st, element);
}

//------------------------------------------------------------------------------------

void reverse_sentence(string s)
{

    stack<string> st;

    for (int i = 0; i < s.length(); i = i + 1)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word = word + s[i];
            i = i + 1;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return;
}

//------------------------------------------------------------------------------------

int postfix_eval(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] < '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op_2 = st.top();
            st.pop();
            int op_1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op_1 + op_2);
                break;

            case '-':
                st.push(op_1 - op_2);
                break;

            case '*':
                st.push(op_1 * op_2);
                break;

            case '/':
                st.push(op_1 / op_2);
                break;

            case '^':
                st.push(pow(op_1, op_2));
                break;
            }
        }
    }
    return st.top();
}

//------------------------------------------------------------------------------------

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i = i + 1)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res = res + s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res = res + st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (prec(st.top()) > prec(s[i])))
            {
                res = res + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res = res + st.top();
        st.pop();
    }

    return res;
}

//------------------------------------------------------------------------------------

string infix_to_prefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i = i + 1)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res = res + s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res = res + st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (prec(st.top()) > prec(s[i])))
            {
                res = res + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res = res + st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

//------------------------------------------------------------------------------------

int prefix_eval(string s)
{
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i = i - 1)
    {
        if (s[i] >= '0' && s[i] < '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op_1 = st.top();
            st.pop();
            int op_2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op_1 + op_2);
                break;

            case '-':
                st.push(op_1 - op_2);
                break;

            case '*':
                st.push(op_1 * op_2);
                break;

            case '/':
                st.push(op_1 / op_2);
                break;

            case '^':
                st.push(pow(op_1, op_2));
                break;
            }
        }
    }
    return st.top();
}

//------------------------------------------------------------------------------------

string redundant_parenthesis(string s)
{
    stack<char> st;
    string ans = "No redundant parenthesis";

    for (int i = 0; i < s.size(); i = i + 1)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (st.top() == '(' || st.top() == '[' || st.top() == '{')
            {
                ans = " redundant parenthesis";
            }

            while (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
            {
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}

//------------------------------------------------------------------------------------

string is_valid(string s)
{
    int n = s.size();
    stack<char> st;
    string ans = "valid string";

    for (int i = 0; i < n; i = i + 1)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = "Invalid string";
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = "Invalid string";
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = "Invalid string";
                break;
            }
        }
    }
    if (!st.empty())
    {
        return ans = "Invalid string";
    }
    if (ans == "valid string")
    {
        cout << redundant_parenthesis(s) << endl;
    }

    return ans;
}

//------------------------------------------------------------------------------------

int max_area(vector<int> a)
{
    int n = a.size(), ans = 0;
    stack<int> st;
    a.push_back(0);

    for (int i = 0; i < n; i = i + 1)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            int h = a[st.top()];
            st.pop();
            if (st.empty())
            {
                ans = max(ans, h * i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i);
    }
    return ans;
}

//------------------------------------------------------------------------------------

int rain_water(vector<int> a)
{
    stack<int> st;
    int n = a.size();
    int ans = 0;

    for (int i = 0; i < n; i = i + 1)
    {
        while (!st.empty() && a[i] > (a[st.top()]))
        {
            int con = st.top();
            st.pop();

            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans = ans + diff * (min(a[st.top()], a[i]) - a[con]);
        }
        st.push(i);
    }
    return ans;
}

//------------------------------------------------------------------------------------

vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;

    stack<pair<int, int>> s;
    for (auto price : prices)
    {
        int days = 1;
        while (!s.empty() && s.top().first <= price)
        {
            days = days + s.top().second;
            s.pop();
        }
        s.push({price, days});
        ans.push_back(days);
    }

    return ans;
}

//------------------------------------------------------------------------------------

class Stack_using_Que_1
{
    int N;
    queue<int> q1;
    queue<int> q2;

    //------------------------------------------------------------------------------------
public:
    Stack_using_Que_1()
    {
        N = 0;
    }

    //------------------------------------------------------------------------------------

    void push(int val)
    {
        q2.push(val);
        N = N + 1;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    //------------------------------------------------------------------------------------

    void pop()
    {
        q1.pop();
        N = N - 1;
    }

    //------------------------------------------------------------------------------------

    int top()
    {
        return q1.front();
    }

    //------------------------------------------------------------------------------------

    int size()
    {
        return N;
    }
};

//------------------------------------------------------------------------------------

class Stack_using_Que_2
{
    int N;
    queue<int> q1;
    queue<int> q2;

    //------------------------------------------------------------------------------------
public:
    Stack_using_Que_2()
    {
        N = 0;
    }

    //------------------------------------------------------------------------------------

    void push(int val)
    {
        q1.push(val);
        N = N + 1;
    }

    //------------------------------------------------------------------------------------

    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        else
        {
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            N = N - 1;

            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
        }
    }

    //------------------------------------------------------------------------------------

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        else
        {
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int ans = q1.front();
            q2.push(ans);
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
            return ans;
        }
    }

    //------------------------------------------------------------------------------------

    int size()
    {
        return N;
    }
};

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

int main()
{

    return 0;
}