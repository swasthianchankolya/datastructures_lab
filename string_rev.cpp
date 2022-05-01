#include<iostream>
#include<string>
using namespace std;

void stringrev(string str1)
{
    int len=str1.length();
    string str2[len];

    int i=0;
    int j=len-1;
    while(j>=0)
    {
        str2[i]=str1[j];
        i++;
        j--;
    }
    for(int k=0;k<len;k++)
    {
        cout<<str2[k];
    }
}


int main()
{
    string str1;
    string str2;

    cout<<"enter the string 1:";
    cin>>str1;
    stringrev(str1);
    return 0;
}