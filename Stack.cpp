#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
        cout<< val <<" pushed"<<endl;
    }
    void pop()
    {
        sz--;
        Node *deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }

        delete deleteNode;
        cout<<"Poped"<<endl;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    myStack st;
    cout << "Choose your option."<< endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Size" << endl;
    cout << "5. Empty" << endl;
    cout << "6. Exit" << endl;

    while (true)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (n == 2)
        {
            st.pop();
        }
        else if (n == 3)
        {
            cout << "Value at Top: " << st.top() << endl;
        }
        else if (n==4)
        {
            cout << "Stack Size -> " << st.size() << endl;
        }
        else if (n==5)
        {
            cout << "Stack is empty! -> " << st.empty() << endl;
        }
        else if (n==6)
        {
            return 0;
        }
        else{
            cout << "Invalid Input" << endl;
            return 0;
        }
    }
   
    return 0;
}