#include<iostream>
using namespace std;
/*
@swasthiiiiii
*/
typedef struct node
{
    struct node *ptr;
    int data;
}NODE;

class slist
{
    public:
        NODE *insert(NODE *);
        NODE *reverse(NODE *);
        void display(NODE *);
};
NODE *slist::insert(NODE *head)
{
    NODE *newnode;
    int num;
    newnode=(NODE *)malloc(sizeof(NODE));
    cout<<"enter the node:";
    cin>>num;

    newnode->data=num;
    newnode->ptr=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->ptr=head;
        head=newnode;
    }
    return head;
}
void slist::display(NODE *head)
{
    NODE *temp;
    if(head==NULL)
    {
        cout<<"list is empty\n";
    }
    else
    {
       temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->ptr;
        } 
    }
}
NODE *slist::reverse(NODE *head)
{
    NODE *prev,*curr,*next;

    prev=NULL;
    curr=head;
    next=head;

    while(curr!=NULL)
    {
        next=curr->ptr;
        curr->ptr=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
int main()
{
    NODE *head=NULL;
    slist s;
    int ch;

    while(1)
    {
        cout<<"\n1.insert\n";
        cout<<"2.reverse\n";
        cout<<"3.display\n";
        cout<<"4.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:head=s.insert(head);
            break;
            case 2:head=s.reverse(head);
            break;
           case 3:s.display(head);
            break;
            case 4:exit(0);
            break;
        }
    }
    return 0;
}