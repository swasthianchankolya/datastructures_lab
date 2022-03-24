#include<iostream>
using namespace std;
/*
@swasthiiiiii
*/
int main()
{
    int mat1[3][3];
    int mat2[3][3];
    int mat3[3][3];
    int mat4[3][3];
    int mat5[3][3];

    int num;
    int k=0;
    int l=0;

    cout<<"enter the marix 1:";

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>num;
            mat1[i][j]=num;
        }
    }
    /*
    */
    cout<<"first matrix is:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         cout<<mat1[i][j]<<"\t";
        }
        cout<<"\n";
    }
    /*

    */


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat1[i][j]!=0)
            {
                mat2[l][0]=i;
                mat2[l][1]=j;
                mat2[l][2]=mat1[i][j];
                l++;
            }
        }
    }
    /*
    */
    cout<<"sparse matrix 1 is:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         cout<<mat2[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
    cout<<"\nenter the marix 2:";

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>num;
            mat3[i][j]=num;
        }
    }

    cout<<"second matrix is:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         cout<<mat3[i][j]<<"\t";
        }
        cout<<"\n";
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat3[i][j]!=0)
            {
                mat4[k][0]=i;
                mat4[k][1]=j;
                mat4[k][2]=mat3[i][j];
                k++;
            }
        }
    }

    cout<<"sparse matrix 2 is:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         cout<<mat4[i][j]<<"\t";
        }
        cout<<"\n";
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         mat5[i][j]=mat2[i][j]+mat4[i][j];
        }
    }

    cout<<"sum of sparse is \n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        cout<<mat5[i][j]<<"\t";
        }
        cout<<"\n";
    }


    return 0;
}