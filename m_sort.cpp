#include<iostream>
using namespace std;



void merge(int arr[],int s,int e)
{
    int m=(s+e)/2;

    int len1=m-s+1;
    int len2=e-m;


    int first[len1];
    int second[len2];


    int mainindex=s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[mainindex];
        mainindex++;
    }

    mainindex=m+1;
    for(int i=0;i<len1;i++)
    {
        second[i]=arr[mainindex];
        mainindex++;
    }


    int index1=0;
    int index2=0;
    mainindex=s;


    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainindex]=first[index1];
            mainindex++;
            index1++;
        }
        else
        {
            arr[mainindex]=second[index2];
            mainindex++;
            index2++;
        }
    }
    while(index1<len1)
    {
        arr[mainindex]=first[index1];
        mainindex++;
        index1++;
    }
    while(index2<len2)
    {
        arr[mainindex]=second[index2];
        mainindex++;
        index2++;
    }


}
void merge_sort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int m=(s+e)/2;



    merge_sort(arr,s,m);
    merge_sort(arr,m+1,e);

    merge(arr,s,e);
}





int main()
{
    int n;
    cout<<"enter the array size:";
    cin>>n;
    int arr[n];
    cout<<"enter the data";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}