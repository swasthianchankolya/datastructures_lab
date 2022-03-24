#include<iostream>
#include<stack>
#include<string>
using namespace std;


int postfix_eval(string exp)
{
    stack<int> st;
    for (int i=0;i<exp.length();i++)
    {
    if(exp[i]>='0' && exp[i]<='9')
            {
            st.push(exp[i]-'0');
            }
    else
            {
             int op2=st.top();
             st.pop();
             int op1=st.top();
             st.pop();

             switch (exp[i])
             {
                 case '+':st.push(op1+op2);
                 break;
                 case '-':st.push(op1-op2);
                 break;
                 case '*':st.push(op1*op2);
                 break;
                 case '/':st.push(op1/op2);
             }   
            }
    }
    return st.top();
    
}
int main()
{
    string exp;
    cout<<"enter the expression:";
    cin>>exp;
    string ans;
    cout<<postfix_eval(exp);
    return 0;
}