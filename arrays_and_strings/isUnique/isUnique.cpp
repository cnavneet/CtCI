#include<bits/stdc++.h>
using namespace std;

bool isUnique(string s)
{
    if(s.length() > 128)
        return false;
    
    bool visited[128] = {false};
    for(int i = 0;i<s.length();++i)
    {
        if(visited[s[i]])
            return false;
        visited[s[i]] = true;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    cout<<isUnique(s)<<"\n";
    return 0;
}