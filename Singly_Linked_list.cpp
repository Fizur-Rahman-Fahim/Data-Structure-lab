#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;  
    Node(int val)
    {
        this->val=val;
        this->next=NULL;

    }
};

void insert_at_head(Node* &head , int v)
{
    Node* newnode= new Node(v);
    newnode->next=head;
    head=newnode;
    cout<<"Inserted at head"<<endl<<endl;
}
void insert_at_any_position(Node* head,int v,int p)
{
    Node* newnode= new Node(v);
    Node* tmp=head;
    for(int i=1;i<p-1;i++)
    {
        tmp=tmp->next;
        if(tmp==NULL)
        {
            cout<<"Invalid position"<<endl<<endl;
            return;
        }
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
    cout<<"Inserted at "<<p<<endl<<endl;
}

void insert_at_tail(Node* &head,int v)
{
    Node* newnode= new Node(v);
    if(head==NULL)
    {
        head = newnode;
        cout<<"Inserted at head.";
        return;
    }

    Node* tmp=head;

    while(tmp->next!=NULL)
    {
        tmp = tmp->next;

    }
    tmp->next=newnode;
    cout<<"Inserted at tail"<<endl<<endl;
}

void print_link_list(Node* head)
{
    Node* tmp = head;

    cout<<endl;
    cout<<"Your linked list is: ";
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl<<endl;
}

void delete_position(Node* head, int po)
{
    Node*tmp =head;
    for(int i=1;i<po-1;i++)
    {
        tmp=tmp->next;
        if(tmp==NULL)
        {
            cout<<"Invalid position"<<endl<<endl;
            return;
        }
    }
    if(tmp->next==NULL)
        {
            cout<<"Invalid position"<<endl<<endl;
            return;
        }
    Node* deletenode= tmp->next;
    tmp->next=tmp->next->next;
    delete deletenode;
    cout<<"Position deleted."<<endl<<endl;
}
void delete_head(Node* &head)
{
    if(head==NULL)
        {
            cout<<"Please insert head"<<endl<<endl<<endl;
            return;
        }
    Node* deletenode=head;
    head=head->next;
    delete deletenode;
    cout<<"Head deleted."<<endl<<endl;
}

int main()
{
   
    Node* head =NULL;

    while(true)
    {
        cout<<"Option-1: Insert at tail."<<endl;
        cout<<"Option-2: Terminate."<<endl;
        cout<<"Option-3: Print list."<<endl;
        cout<<"Option-4: Insert at head."<<endl;
        cout<<"Option-5: Insert at any position."<<endl;
        cout<<"Option-6: Delete any position."<<endl;
        cout<<endl<<endl;
        cout<<"Please choose an option: ";
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<endl;
            cout<<"Enter value: ";
            int val;
            cin>>val;
            cout<<endl;
            insert_at_tail(head,val);
        }
        else if(op==2)
        {
            break;
        }
        else if (op==3)
        {
            print_link_list(head);
        }
        else if(op==4)
        {
            cout<<endl;
            cout<<"Enter value: ";
            int val;
            cin>>val;
            cout<<endl;
            insert_at_head(head,val);
        }
        else if(op==5)
        {
            cout<<endl;
            cout<<"Enter position: ";
            int pos;
            cin>>pos;
            cout<<endl<<endl;
            cout<<"Enter value: ";
            int val;
            cin>>val;
            cout<<endl;
            if(pos==1)
            {
                insert_at_head(head,val);
            }
            else
            {
                insert_at_any_position(head,val,pos);
            }
            
        }
        else if (op==6)
        {
            int position;
            cout<<endl<<endl;
            cout<<"Enter position: ";
            cin>>position;
            cout<<endl<<endl;
            if(position==1)
            {
                delete_head(head);
            }
            else
            {
                delete_position(head,position);
            }
           
        }
    }
    return 0;
}