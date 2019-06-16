#include<bits/stdc++.h>
using namespace std;

long long int Insertion(long long int n, long long int m, long long int i, long long int j)
{
    // cout<<"n = "<<n<<"\n";
    // cout<<"m = "<<m<<"\n";
    // cout<<"i = "<<i<<"\n";
    // cout<<"j = "<<j<<"\n";
    long long int ones = -1;
    // cout<<"ones = "<<ones<<"\n";
    long long int left = ones << (j+1);
    // cout<<"left = "<<left<<"\n";
    long long int right = ((1<<i) - 1);
    // cout<<"right = "<<right<<"\n";
    long long int mask = left | right;
    // cout<<"mask = "<<mask<<"\n";
    long long int n_cleared = n & mask;
    // cout<<"n_cleared = "<<n_cleared<<"\n";
    long long int m_shifted = m<<i;
    // cout<<"m_shifted = "<<m_shifted<<"\n";
    long long int res = n_cleared | m_shifted;
    return res;
}

int main()
{
    long long int n = 10000000000;
    long long int m = 1001;
    long long int i = 2;
    long long int j = 6;
    long long int res = Insertion(n, m, i, j);
    cout<<res<<"\n";
    return 0;
}