#include<iostream>
using namespace std;

class p_q
{
    int front,rear;
    int q[5];
    int max=5;
    public:
    p_q()
        {
            front=-1;
            rear=-1;
        }
    void fninsert();
    void fndelete();
    void fndisplay();
    
};

void p_q::fninsert()
{
    int ele;
    if(rear==max-1)
    {
        cout<<"q is full\n";
    }
    else
    {
        cout<<"enter the elements:";
        cin>>ele;
        rear=rear+1;
        q[rear]=ele;
        if(front==-1)
        {
            front=0;
        }
    }
}
void p_q::fndisplay()
{
    if(front==-1)
    {
        cout<<"emtpy\n";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<q[i];
        }
    }
}
void p_q::fndelete()
{
    int min,index;
    if(rear==-1)
    {
        cout<<"empty\n";
    }
    else
    {
        min=q[0];
        index=0;
        for(int i=1;i<=rear;i++)
        {
            if(min>q[i])
            {
                min=q[i];
                index=i;
            }
        }
        cout<<"deleted:"<<min;
        for(int i=index;i<rear;i++)
        {
            q[i]=q[i+1];
        }
        rear=rear-1;
    }
}
int main()
{
    int ch;
    p_q c;
    while(1)
    {
        cout<<"\n1.insert\n";
        cout<<"2.delete\n";
        cout<<"3.display\n";
        cout<<"4.exit\n";
        cin>>ch;

        switch(ch)
        {
            case 1:c.fninsert();
            break;
            case 2:c.fndelete();
            break;
            case 3:c.fndisplay();
            break;
            case 4:exit(0);
            break;
        }
    }
    return 0;
}