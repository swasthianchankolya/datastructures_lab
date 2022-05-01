#include<iostream>
using namespace std;

class queue
{
    int front,rear,max=5,arr[5];
    public:
    queue()
    {
        front=-1;
        rear=-1;
    }
    void insert();
    void delet();
    void display();
};

void queue::insert()
{
    int num;
    if(rear==max-1)
    {
        cout<<"queue is full\n";
    }
    else
    {
        cout<<"enter the element:";
        cin>>num;
        rear=rear+1;
        arr[rear]=num;
        if(front==-1)
        {
            front=0;
        }
    }
}

void queue::display()
{
    if(front==-1)
    {
        cout<<"queue is empty:\n";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
}
void queue::delet()
{
    int num;
    if(front==-1)
    {
        cout<<"queue is empty\n";
    }
    else
    {
        num=arr[front];
        cout<<"deleted:"<<num;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
    }
}


int main()
{
    int ch;
    queue q;
    while(1)
    {
        cout<<"\n1.insert\n";
        cout<<"2.delete\n";
        cout<<"3.display\n";
        cout<<"4.exit\n";
        cout<<"enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:q.insert();
            break;
            case 2:q.delet();
            break;
            case 3:q.display();
            break;
            case 4:exit(0);
            break;
        }
    }
    return 0;
}