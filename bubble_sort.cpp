#include<iostream>
using namespace std;

void b_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int temp=0;
        for(int j=0;j<n-i-1;j++)
        {
         if(arr[j]>arr[j+1])
         {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
         }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

}

int main()
{
    int n;
    cout<<"enter the arraay size:";
    cin>>n;
    int arr[n];
    cout<<"enter the array elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    b_sort(arr,n);
    return 0;
}