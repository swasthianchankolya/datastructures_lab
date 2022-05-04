#include<iostream>
using namespace std;

int partition(int arr[],int s,int e)
{
    int pivot=arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }

    //place pivot at right position
    int pivotindex=s+count;
    swap(arr[pivotindex],arr[s]);

    //left and right 
    int i=s,j=e;

    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<pivotindex && j>pivotindex)
        {
          swap(arr[i],arr[j]);
          i++;
          j--;
        }
    }  

}


void quicksort(int arr[],int s,int e)
{
if(s>=e)
{
    return;
}
int p=partition(arr,s,e);

//left part sort
quicksort(arr,s,p-1);

//right part
quicksort(arr,p+1,e);
}





int main()
{
    int size;
    cout<<"enter the size:";
    cin>>size;
    int arr[size];
    cout<<"enter the data:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,size);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
    return 0;
}