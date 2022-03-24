#include<iostream>
#include<stack>
using namespace std;
/*
@swasthiiiiii
*/

//this function whill return true if entred charecter is operater
bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// this function will return the prcedence of operator
int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		/*if the values is charecter then just add it to
         postfix string
		*/
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}

		/*
        if the charecter is ( then push it to the stack
		*/
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}

		/*
		if the charecter is ) then pop the all the elements
		untill you get (
		*/
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}

		/*
		if the charecter is operator and stack is empty then just
		push it to the stack no bcz there are no other
		elements to compare the precedence
		*/
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				/*
				if many elements are there in stack and 
				precendence of top of stack is less then 
				the new charecter then just push it to the stack
				*/
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}
				/*
                if the stack top is ^ and new character is also ^ 
				then instead of popping it push it to the stack
				bcz in ^ operator precedence checked from right to left
				*/	
		else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
		{
			s.push(infix[i]);
		}
				else
				{
					/*
                    except ^ if the new operators precedence is
					 less then or equal to the top element then pop 
					 the top and add it to posrfix,and check again 
					 untill u find the top whos predence is less then
					  new charecter or untill stack is empty 
					*/
		while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
		{
		postfix+=s.top();
		s.pop();
		}
					/*
					at last push that new charecter to the stack
					*/
					s.push(infix[i]);
				}
			}
		}
	}
	/*
	now here pop all the elemets and add it to
	 postfix untill stack is empty
	*/
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  

  	string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;
  	stack <char> stack;
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(stack, infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
	  
	return 0;
}