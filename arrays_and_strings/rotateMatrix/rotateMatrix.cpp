#include<bits/stdc++.h>
using namespace std;

int **arr;
int n;

void RotateMatrix()
{
    for(int i = 0;i<n;++i)
    {
        for(int j = i;j<n;++j)
        {
            swap(arr[j][i], arr[i][j]);
        }
    }

    for(int i = 0;i<n/2;++i)
    {
        for(int j = 0;j<n;++j)
        {
            swap(arr[i][j], arr[n-1-i][j]);
        }
    }
}

int main()
{
    cin>>n;
    arr = new int*[n];
    for(int i = 0;i<n;++i)
    {
        arr[i] = new int[n];
        for(int j = 0;j<n;++j)
        {
            cin>>arr[i][j];
        }
    }

    RotateMatrix();
    for(int i = 0;i<n;++i)
    {
        for(int j = 0;j<n;++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}