#include<iostream>
using namespace std;

/*
@swasthiiiiii
*/
 void findsub(char str[],char substr[])
     { 
        int i,j,temp;
        for(i=0;str[i]!='\0';i++)
         {
            j=0;
            if(str[i]==substr[j])
                {
                    temp=i+1;
                    while(str[i]==substr[j])
                        {
                            i++;
                            j++;
                        }
            
                       if(substr[j]=='\0')
                         {
                         cout<<"found at"<<temp;
                         exit(0);
                         }
                         else
                          {
                          i=temp;
                          temp=0;
                          }
                }
        }
 
        if(temp==0)
        {
        cout<<"not found";
        }
     }
int main()
{
    char str[100];
    char substr[20];
    cout<<"enter the main string:";
    cin>>str;
    cout<<"enter the substring:";
    cin>>substr;

    findsub(str,substr);
    return 0;
}

    