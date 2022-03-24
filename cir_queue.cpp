#include<iostream>
using namespace std;

class c_q
{
    int front,rear;
    int q[5];
    int max=5;
    public:
    c_q()
        {
            front=-1;
            rear=-1;
        }
    void fninsert();
    void fndelete();
    void fndisplay();
    
};

void c_q::fninsert()
{
int ele;
if((rear+1)%max==front)
{
    cout<<"q is full";
}
else
{
    cout<<"enter the element:";
    cin>>ele;
    rear=(rear+1)%max;
    q[rear]=ele;

    if(front==-1)
    {
        front=0;
    }
}
}
void c_q::fndelete()
{
if(front==-1)
{
    cout<<"q is empty\n";
}
else
{

    int obj=q[front];
    cout<<"deleted:"<<obj;
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%max;
    }
}
}

void c_q::fndisplay()
{
if(front==-1)
{
    cout<<"q is empty\n";
}
else
{
if(front<=rear)
{
    for(int i=front;i<=rear;i++)
    {
        cout<<q[i];
    }
}
else
{
    for(int i=front;i<=max-1;i++)
    {
        cout<<q[i];
    }
    for(int j=0;j<=rear;j++)
    {
        cout<<q[j];
    }
}
}
}
int main()
{
    int ch;
    c_q c;
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