#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}NODE;

class doubly_cl
{
    public:
    NODE *fninsertbegin(NODE*);
    NODE *fninsertend(NODE*);
    NODE *fninsertpos(NODE*,int);
    NODE *fndeletebegin(NODE*);
    NODE *fndeleteend(NODE*);
    NODE *fndeletepos(NODE*,int);
    void display(NODE*);

};

NODE *doubly_cl::fninsertbegin(NODE *head)
{
    NODE *newnode,*temp;
    int num;
    newnode=(NODE *)malloc(sizeof(NODE));
    cout<<"enter the node:";
    cin>>num;
    newnode->data=num;
    newnode->left=newnode;
    newnode->right=newnode;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
    temp=head;
    while(temp->right!=head)
    {
        temp=temp->right;
    }
    temp->right=newnode;
    newnode->right=head;
    head->left=newnode;
    newnode->left=temp;
    head=newnode;
    }
  return head;
}
NODE *doubly_cl::fninsertend(NODE *head)
{
    NODE *newnode,*temp;
    int num;
    cout<<"enter the node:";
    cin>>num;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=num;
    newnode->right=newnode;
    newnode->left=newnode;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->right!=head)
        {
            temp=temp->right;
        }
        temp->right=newnode;
        newnode->left=temp;
        newnode->right=head;
        head->left=newnode;
    }
    return head;
}
NODE *doubly_cl::fninsertpos(NODE *head,int pos)
{
    int count=0,num;
    NODE *newnode,*temp,*temp1,*temp2,*temp3;
    
    if(head!=NULL)
    {
      temp=head;
      while(temp->right!=head)
      {
          count++;
          temp=temp->right;
      }
      count++;  
    }
    if(pos>count)
    {
        cout<<"invalid position";
    }
    else
    {
        cout<<"enter the node:";
        cin>>num;
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=num;
        newnode->right=newnode;
        newnode->left=newnode;
        if(pos==0 &&head==NULL)
        {
        head=newnode;
        }
        else if(pos==0)
        {
         temp1=head;
         while(temp1->right!=head)
         {
             temp1=temp1->right;
         }
         temp1->right=newnode;
         newnode->left=temp1;
         newnode->right=head;
         head->left=newnode;
         head=newnode;
        }
        else if(pos==count)
        {
            temp1=head;
            while(temp1->right!=head)
            {
               temp1=temp1->right;   
            }
         temp1->right=newnode;
         newnode->left=temp1;
         newnode->right=head;
         head->left=newnode;
        }
        else
        {
            temp2=head;
            for(int i=0;i<pos;i++)
            {
                temp1=temp2;
                temp2=temp2->right;   
            }
            newnode->right=temp2;
            temp2->left=newnode;
            newnode->left=temp1;
            temp1->right=newnode;
        }

    }
    return head;
}
NODE *doubly_cl::fndeletebegin(NODE *head)
{
    NODE *temp,*temp1;;
    if(head==NULL)
    {
        cout<<"lis is empty";
    }
    else
    {
    if(head->right==head)
    {
        cout<<"deleted:"<<head->data;
        head->right=NULL;
        head->left=NULL;
        head=NULL;
        free(head);
    }
    else
    {
        temp1=head;
        temp=head;
        while(temp->right!=head)
        {
            temp=temp->right;
        }
        head=head->right;
        head->left=temp;
        temp->right=head;
        cout<<"deleted:"<<temp1->data;
        temp1->left=NULL;
        temp1->right=NULL;
        free(temp1);
        
    }
    }
    return head;
}
NODE *doubly_cl::fndeleteend(NODE *head)
{
    NODE *temp1,*temp2;;
    if(head==NULL)
    {
        cout<<"lis is empty";
    }
    else
    {
    if(head->right==head)
    {
        cout<<"deleted:"<<head->data;
        head->right=NULL;
        head->left=NULL;
        head=NULL;
        free(head);
    }
    else
    {
        temp2=head;
        while(temp2->right!=head)
        {
            temp1=temp2;
            temp2=temp2->right;
        }
        cout<<"deleted:"<<temp2->data;
        temp2->right=NULL;
        temp2->left=NULL;
        free(temp2);
        head->left=temp1;
        temp1->right=head;
    }
    }
    return head;
}
NODE *doubly_cl::fndeletepos(NODE *head,int pos)
{
    NODE *temp,*temp1,*temp2,*temp3;
    int count=0;
    
    if(head!=NULL)
    {
        temp=head;
        while(temp->right!=head)
        {
            count++;
            temp=temp->right;
        }
        count++;
    }
    if(pos>count)
    {
        cout<<"invalid position";
    }
    else
    {
        if(pos==1 && head->right==head)
        {
            cout<<"deleted:"<<head->data;
            head->left=NULL;
            head->right=NULL;
            head=NULL;
            free(head);
        }
        else if(pos==1)
        {
        temp1=head;
        temp2=head;
        while(temp2->right!=head)
        {
            temp2=temp2->right;
        }
        head=head->right;
        head->left=temp;
        temp2->right=head;
        cout<<"deleted:"<<temp1->data;
        temp1->left=NULL;
        temp1->right=NULL;
        free(temp1); 
        }
        else if(pos==count)
        {
        temp2=head;
        while(temp2->right!=head)
        {
            temp1=temp2;
            temp2=temp2->right;
        }
        cout<<"deleted:"<<temp2->data;
        temp2->right=NULL;
        temp2->left=NULL;
        free(temp2);
        head->left=temp1;
        temp1->right=head;
        }
        else
        {
            temp2=head;
            for(int i=1;i<pos;i++)
            {
                temp1=temp2;
                temp2=temp2->right;
            }
            temp3=temp2->right;
            temp1->right=temp3;
            temp3->left=temp1;
            cout<<"deleted:"<<temp2->data;
            temp2->left=NULL;
            temp2->right=NULL;
            free(temp2);
        }
    }

    return head;
}
void doubly_cl::display(NODE *head)
{
    NODE *temp;
    if(head==NULL)
    {
        cout<<"list is empty\n";
    }
    else
    {
    temp=head;
    while(temp->right!=head)
    {
        cout<<temp->data<<"\t";
        temp=temp->right;
    }
    cout<<temp->data;
    }
}

int main()
{
    int pos,ch;
    NODE *head=NULL;
    doubly_cl dcl; 
    while(1)
    {
    cout<<"\n1.insert begin\n";
    cout<<"2.insert end\n";
    cout<<"3.insert positon\n";
    cout<<"4.delete begin\n";
    cout<<"5.delete end\n";
    cout<<"6.delete position\n";
    cout<<"7.display\n";
    cout<<"8.exit\n";
    cout<<"enter the choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:head=dcl.fninsertbegin(head);
    break;
    case 2:head=dcl.fninsertend(head);
    break;
    case 3:cout<<"enter the position:";
           cin>>pos;
           head=dcl.fninsertpos(head,pos);
           break;
    case 4:head=dcl.fndeletebegin(head);
    break;
    case 5:head=dcl.fndeleteend(head);
    break;
    case 6:cout<<"enter the position:";
           cin>>pos;
           head=dcl.fndeletepos(head,pos);
           break;
    case 7:dcl.display(head);
    break;
    case 8:exit(0);
    break;
    }
    }

    return 0;
}