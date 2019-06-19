#include<bits/stdc++.h>
using namespace std;

int BitsSwapped(int a, int b)
{
    int Count = 0;
    for(int i = a^b; i!=0;i = i & (i-1))
    {
        Count++;
    }
    return Count;
}

int main()
{
    int n, m;
    cin>>n>>m;
    int ans = BitsSwapped(n, m);
    cout<<ans<<"\n";
    return 0;
}