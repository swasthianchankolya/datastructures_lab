#include<iostream>
#include<string.h>
using namespace std;

/*
@swasthiiiiii
*/
void stringcopy(string s1)
{
    int l=s1.length();
    string s2;

    for(int i=0;i<l;i++)
    {
        s2[i]=s1[i];
    }
    cout<<"after copy\n";
    for(int i=0;i<l;i++)
    {
        cout<<s2[i];
    }
}

int main()
{
    string s1;
    cout<<"enter the string 1:";
    cin>>s1;
    stringcopy(s1);
    return 0;
}