#include<iostream>
using namespace std;
typedef struct node
{
    struct node *ptr;
    int data;
}NODE;
class slist
{
    public:
            NODE *insert1(NODE *);
            NODE *reverse1(NODE *);
            void display(NODE *);

};
int main()
{
    NODE *head=NULL;
    slist sl;
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
            case 1:head=sl.insert1(head);
            break;
            case 2:head=sl.reverse1(head);
            break;
            case 3:sl.display(head);
            break;
            case 4:exit(0);
            break;
        }
    }
   return 0;
}

/*
NODE *slist::insert1(NODE *head)
{

    NODE *newnode,*temp;
    int num;
    cout<<"Enter the data for the node:";
    cin>>num;
    newnode=(NODE *)malloc(sizeof(newnode));
    newnode->data=num;
    newnode->ptr=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
       temp=head;
       while(temp->ptr!=NULL)
       {
           temp=temp->ptr;
       }
       temp->ptr=newnode;

    }
    return(head);
}
*/
NODE *slist::insert1(NODE *head)
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
NODE *slist::reverse1(NODE *head)
{
    NODE *prev,*curr,*next;
    prev=NULL;
    curr=next=head;
    while(curr!=NULL)
    {
        next=curr->ptr;
        curr->ptr=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return(head);
}
void slist::display(NODE *head)
{
    NODE *temp;
    if(head==NULL)
    {
        cout<<"\nList is empty";
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
