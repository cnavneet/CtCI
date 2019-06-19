#include<bits/stdc++.h>
using namespace std;

long long int TripleSteps(int n)
{
    long long int arr[n+1];
    arr[0] = 0;
    for(int i = 1;i<=n;++i)
    {
        arr[i] = 0;
        if(i > 1)
        {
            arr[i] += arr[i-1] + 1;
        }
        if(i > 2)
        {
            arr[i] += arr[i-2] + 1;
        }
        if(i > 3)
        {
            arr[i] += arr[i-3] + 1;
        }
    }
    return arr[n];
}

int main()
{
    int n;
    cin>>n;
    assert(n<1000000000);
    long long int res = TripleSteps(n);
    cout<<res<<"\n";
    return 0;
}