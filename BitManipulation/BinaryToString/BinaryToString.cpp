#include<bits/stdc++.h>
using namespace std;

string binaryToString(double num)
{
    if(num >= 1 || num<=0)
    {
        return "ERROR";
    }

    string res = "";
    res = res + '.';
    while(num > 0)
    {
        if(res.length() >= 32)
        {
            return "ERROR";
        }
        
        double r = num * 2;
        if(r>=1)
        {
            res = res + '1';
            num = r - 1;
        }
        else
        {
            res = res + '0';
            num = r;
        }
    }
    return res;
}

int main()
{
    double n = 0.72;
    string ans = binaryToString(n);
    cout<<ans<<"\n";
    return 0;
}