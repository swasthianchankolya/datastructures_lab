#include<iostream>
using namespace std;


void merge(int *arr,int s,int e)
{
    int mid=(s+e)/2;

    //length of first array
    int len1=mid - s + 1;

    //length of second array
    int len2=e - mid;

    int *first=new int[len1];
    int *second=new int[len2];


    //copying first array
    int mainindex=s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[mainindex++];
    }
    //copying second array
    mainindex=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainindex++];
    }


    //merging the array
    int index1=0;
    int index2=0;
    mainindex=s;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            arr[mainindex++]=first[index1++];
        }
        else
        {
            arr[mainindex++]=second[index2++];
        }
    }

    while(index1 < len1)
    {
        arr[mainindex++]=first[index1++];
    }
    while(index2 < len2)
    {
        arr[mainindex++]=second[index2++];
    }
  

  //at last printing the sorted array


    

}
void merge_sort(int *arr,int s,int e)
{
   if(s >= e)
   {
       return;
   }

   int mid=(s+e)/2;

   //recurssion on first half
   merge_sort(arr,s,mid);

   //recursion on second half
   merge_sort(arr,mid+1,e);

   //mergeing both half
   merge(arr,s,e);
}


int main()
{
    int arr[5]={1,4,5,0,2};
    int n=5;

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}