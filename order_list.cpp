#include<iostream>
using namespace std;

typedef struct node
{
    struct node *ptr;
    int data;
}NODE;

class list
{
public:
  NODE *insert(NODE *);
  void display(NODE *);
};

NODE *list::insert(NODE *head)
{
    NODE *newnode,*temp1,*temp2;
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
    else if(newnode->data <= head->data)
    {
        newnode->ptr=head;
        head=newnode;
    }
    else
    {
        temp2=head;
        while(temp2!=NULL && temp2->data < newnode->data)
        {
            temp1=temp2;
            temp2=temp2->ptr;
        }
        temp1->ptr=newnode;
        newnode->ptr=temp2;

    }
    return head;
}

void list::display(NODE *head)
{
    NODE *temp;
    if(head==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        temp=head;
        while(temp->ptr!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->ptr;
        }
        cout<<temp->data;
    }
}


int main()
{
    int ch;
    list l;
    NODE *head=NULL;
    while(1)
    {
        cout<<"\n1.insert\n";
        cout<<"2.display\n";
        cout<<"4.exit\n";
        cout<<"enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:head=l.insert(head);
            break;
            case 2:l.display(head);
            break;
            case 4:exit(0);
            break;
        }
    }
    return 0;
}