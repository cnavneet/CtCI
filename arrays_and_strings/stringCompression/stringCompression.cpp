#include<bits/stdc++.h>
using namespace std;

string CompressedString(string s)
{
    string ans = "" + s[0];
    int Count = 1;
    for(int i = 1;i<s.length();++i)
    {
        if(s[i] == s[i-1])
            Count++;
        else
        {
            ans += to_string(Count);
            Count = 1;
            ans += s[i];
        }
    }
    ans += to_string(Count);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<CompressedString(s)<<"\n";
    return 0;
}