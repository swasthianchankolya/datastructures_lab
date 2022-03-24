#include<iostream>
using namespace std;

class stackcls
{
int top=-1;
int size=5;
int stk[5];

public:
void push()
{
    int ele;
    if(top==size-1)
    {
        cout<<"stack is full\n";
    }
    else
    {
        cout<<"enter the element:";
        cin>>ele;
        top=top+1;
        stk[top]=ele;
    }
}
void display()
{
    if(top==-1)
    {
        cout<<"stack is empty";
    }
    else
    {
        for(int i=top;i>0;i--)
        {
            cout<<stk[i];
        }
    }
}
void pop()
{
    int ele;
    if(top==-1)
    {
        cout<<"stack is empty\n";
    }
    else
    {
     ele=stk[top];
     cout<<"deleted:"<<ele;
     top--;
    }
}
};


int main()
{
    stackcls st;
    int ch;
    while(1)
    {
        cout<<"1.push\n";
        cout<<"2.pop\n";
        cout<<"3.display\n";
        cout<<"4.exit\n";
        cout<<"enter the choice:\n";
        cin>>ch;
        switch (ch)
        {
            case 1:st.push();
            break;
            case 2:st.pop();
            break;
            case 3:st.display();
            break;
            case 4:exit(0);
            break;

        }
    }
    return 0;
}