#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *ptr;
}NODE;

class slist
{
    public:
    NODE *fninsertbegin(NODE *);
    NODE *fninsertend(NODE *);
    NODE *fninsertpos(NODE *,int);
    NODE *fndeletebegin(NODE *);
    NODE *fndeleteend(NODE *);
    NODE *fndeletepos(NODE *,int);
    void fndisplay(NODE *);
};

int main()
{
    NODE *head=NULL;
    slist sl;
    int ch,pos;
    while(1)
    {
        cout<<"\nmenu\n";
        cout<<"1.insert begin\n";
        cout<<"2.insert end\n";
        cout<<"3.insert pos\n";
        cout<<"4.delete begin\n";
        cout<<"5.delete end\n";
        cout<<"6.delete position\n";
        cout<<"7.display\n";
        cout<<"8.exit\n";
        cout<<"enter your choice:";
        cin>>ch;
        switch (ch)
        {
            case 1:head=sl.fninsertbegin(head);
            break;
           /* case 2:sl.fninsertend(head);
            break;
            case 3:sl.fninsertpos(head,pos);
            break;
            case 4:sl.fndeletebegin(head);
            break;
            case 5:sl.fndeleteend(head);
            break;
            case 6:sl.fndeletepos(head,pos);
            break;
            */
            case 7:sl.fndisplay(head);
            break;
            case 8:exit(0);
            }
    }
    return 0;
}
NODE *slist::fninsertbegin(NODE *head)
{
    int num;
    NODE *newnode;
    newnode=(NODE *)malloc(sizeof(newnode));
    cout<<"enter the value for node:\n";
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
void slist::fndisplay(NODE *head) 
{ 
NODE *temp; 
temp=head; 
if(head==NULL) 
{
cout<<"The list is empty"<<endl; 
}
else 
{ 
cout<<"The elements are :"; 
while (temp!=NULL) 
{ 
cout<<temp->data<<" "; 
temp=temp->ptr; 
} 
cout<<endl; 
} 
} 

 