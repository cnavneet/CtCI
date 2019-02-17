#include<bits/stdc++.h>
using namespace std;

bool isPermutation(string s1, string s2)
{
    map<char, int> m1, m2;
    for(int i = 0;i<s1.length();++i)
    {
        m1[s1[i]]++;
        m2[s2[i]]++;
    }
    map<char, int>::iterator it;
    for(it = m1.begin(); it!=m1.end();++it)
    {
        if(m2[it->first] != it->second)
            return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(s1.length() != s2.length())
    {
        cout<<"No\n";
        return 0;
    }

    cout<<isPermutation(s1, s2)<<"\n";
    return 0;
}