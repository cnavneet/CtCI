#include<bits/stdc++.h>
using namespace std;

int FindNext(int n)
{
    int c0 = 0;
    int c1 = 0;
    int c = n;
    while((c & 0 == 0) && (c != 0))
    {
        c0++;
        c>>=1;
    }
    while((c&1) == 1)
    {
        c1++;
        c>>=1;
    }
    if(c1+c0 == 31 || c1+c0 == 0)
        return -1;

    int p = c0 + c1;
    return (n & ~((1<<p)-1)) | ((1<<(c1-1))-1);
}

int FindPrev(int n)
{
    int c = n;
    int c0 = 0;
    int c1 = 0;
    while(c&1 == 1)
    {
        c1++;
        c>>=1;
    }
    if(c==0) 
        return -1;
    while((c&1) == 0 && c!=0)
    {
        c0++;
        c>>=1;
    }
    int p = c0+c1;
    n &= ((~0)<<(p+1));
    int mask = (1<<(c1+1))-1;
    n |= mask << (c0-1);
    return n;
}

int main()
{
    int n;
    cin>>n;
    int next = FindNext(n);
    int prev = FindPrev(n);
    cout<<next<<" "<<prev<<"\n";
    return 0;
}