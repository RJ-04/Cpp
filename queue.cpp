#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

//---------------------------------------------------------------------------

class que
{
    node *head;
    node *tail;

public:
    que()
    {

        node *head = NULL;
        node *tail = NULL;
    }

    //---------------------------------------------------------------------------

    void push(int x)
    {

        node *n = new node(x);

        if (head == NULL)
        {
            tail = n;
            head = n;
            return;
        }
        else
        {
            tail->next = n;
            tail = n;
            return;
        }
    }

    //---------------------------------------------------------------------------

    void pop()
    {
        if (head == NULL)
        {
            cout << "que underflowed";
            return;
        }
        else
        {
            node *to_delete = head;
            head = head->next;
            delete to_delete;
            return;
        }
    }

    //---------------------------------------------------------------------------

    int peek()
    {
        if (head == NULL)
        {
            cout << "No element in que";
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    //---------------------------------------------------------------------------

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//---------------------------------------------------------------------------

class que_using_stack_1
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
        return;
    }

    //---------------------------------------------------------------------------

    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "que is empty";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top_val = s2.top();
        s2.pop();
        return top_val;
    }

    //---------------------------------------------------------------------------

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//---------------------------------------------------------------------------

class que_using_stack_2
{
    stack<int> s;

public:
    void push(int x)
    {
        s.push(x);
        return;
    }

    //---------------------------------------------------------------------------

    int pop()
    {
        if (s.empty())
        {
            cout << "que is empty";
            return -1;
        }
        else
        {
            int x = s.top();
            s.pop();
            if (s.empty())
            {
                return x;
            }
            else
            {
                int item = pop();
                s.push(x);
                return item;
            }
        }
    }

    //---------------------------------------------------------------------------

    bool empty()
    {
        if (s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

int main()
{
    /*  que_using_stack_2 q;

      q.push(1);
      q.push(2);
      q.push(3);

      cout << q.pop() << endl;
      q.push(4);

      cout << q.pop() << endl;
      cout << q.pop() << endl;
      cout << q.pop() << endl;
      cout << q.pop() << endl;
      cout << q.pop() << endl;
      cout << q.pop() << endl;

      cout << q.empty();   */

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i = i + 1)
    {
        while (!q.empty() && (a[q.back()] < a[i]))
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    ans.push_back(a[q.front()]);

    for (int i = k; i < n; i = i + 1)
    {
        if (q.front() == i - k)
        {
            q.pop_front();
        }
        while (!q.empty() && (a[q.back()] < a[i]))
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}