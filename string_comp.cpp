#include<iostream>
#include<string>
using namespace std;


void stringcomp(string str1,string str2)
{
  int len1=str1.length();
  int len2=str2.length();
  int flag=0;
  if(len1!=len2)
  {
      flag=0;
  }
  else
  {
      int i=0;
      while(i<len1)
      {
          if(str1[i]==str2[i])
          {
              flag=1;
          }
          else
          {
              flag=0;
              break;
          }
          i=i+1;
      }
  }
  if(flag==1)
  {
      cout<<"strings are equal";
  }
  else
  {
      cout<<"not equal;";
  }
}
int main()
{
    string str1;
    string str2;

    cout<<"enter the string 1:";
    cin>>str1;
    cout<<"enter the string 2:";
    cin>>str2;
    stringcomp(str1,str2);
    return 0;
}