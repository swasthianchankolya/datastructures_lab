#include<iostream>
#include<string.h>
using namespace std;

void stringcon(string str1,string str2)
{
     string str3[100];    //this is our new string
     int length1=str1.length(); //this is length of  string 1
     int length2=str2.length();//this is length of string 2

     //inserting string 1 to string 3
    for(int i=0;i<length1;i++)
    {
        str3[i]=str1[i];
    }

    //inserting string 2 to string 3
    int i=0;
    for(int j=length1;j<(length1+length2);j++)
    {
        str3[j]=str2[i];
        i++;
    }

    //displaying string 3
    for(int i=0;i<(length1+length2);i++)
    {
        cout<<str3[i];
    }

}

int main()
{
    string str1,str2;
    cout<<"enter the string 1:";
    cin>>str1;
    cout<<"enter the string 2:";
    cin>>str2;

    stringcon(str1,str2);
    return 0;
}