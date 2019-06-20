#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int i = 0;i<n;++i)
    {
        if(a[i] == i)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<"No magic index exists\n";
    return 0;
}