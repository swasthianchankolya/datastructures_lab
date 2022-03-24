#include<iostream>
#define max 5
using namespace std;

/*
@swasthiiiiii
*/

class d_queue
    {
    int front,rear,dq[max];
    public:
          d_queue()
          {
              front=-1;
              rear=-1;
          }
          void fninsertfront();
          void fninsertrear();
          void fndeletefront();
          void fndeleterear();
          void fndisplay();
    };
void d_queue::fninsertrear()
{
    int val;
   if(rear==max-1)
   {
       cout<<"queue is full\n\n";
   }
   else 
   {
       cout<<"enter the value:\n";
       cin>>val;
       rear=rear+1;
       dq[rear]=val;
       if(front==-1)
       {
           front=0;
       }
   }
}
void d_queue::fninsertfront()
{
    int val;
    if(front==0)
    {
        cout<<"cant insert from front\n\n";
    }
    else
    {
        cout<<"enter the value:\n";
        cin>>val;
        if(front==-1)
        {
            front=0;
            rear=0;
            dq[front]=val;
        }
        else
        {
        front--;
        dq[front]=val;
        }
    }
}
void d_queue::fndeleterear()
{
    int val;
    if(front==-1)
    {
        cout<<"queue is empty\n\n";
    }
    else
    {
        val=dq[rear];
        cout<<"deleted:"<<val;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            rear=rear-1;
        }
    }
}

void d_queue::fndeletefront()
{
    int val;
    if(front==-1)
    {
        cout<<"queue is empty\n\n";
    }
    else
    {
     val=dq[front];
     cout<<"deleted:"<<val;
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
void d_queue::fndisplay()
{
    if(front==-1)
    {
        cout<<"queue is empty\n\n";
    }
    else
    {
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<dq[i]<<"\t";
            }
        }
    }
}
int main()
{
    d_queue d;
    int ch;
    while(1)
    {
        cout<<"\n1.insert rear \n";
        cout<<"2.insert front \n";
        cout<<"3..delete rear \n";
        cout<<"4.delete front\n";
        cout<<"5.display\n";
        cout<<"6.exit\n";
        cout<<"enter your choice:\n";
        cin>>ch;
        switch(ch)
        {
            case 1:d.fninsertrear();
            break;
            case 2:d.fninsertfront();
            break;
            case 3:d.fndeleterear();
            break;
            case 4:d.fndeletefront();
            break;
            case 5:d.fndisplay();
            break;
            case 6:exit(0);
        }
    }
    return 0;
}