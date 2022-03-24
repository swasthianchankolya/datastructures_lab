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
    cout<<"Enter the number of nodes:";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        head=sl.insert1(head);
    }
    cout<<"\nContent of Singly Linked List:";
    sl.display(head);
    head=sl.reverse1(head);
    cout<<"\nReverse Of Given Singly LIst Is:";
    sl.display(head);
}

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
