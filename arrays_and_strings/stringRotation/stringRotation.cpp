#include<bits/stc++.h>
using namespace std;

bool checkSubstring(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
    for(int i = 0;i<s1.length();++i)
    {
        string temp = "";
        for(int j = i;j<i+s1.length();++j)
        {
            temp += s1[j%(s.length())];
        }
        if(s2 == temp)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(checkSubstring(s1, s2))
        cout<<"true";
    else
        cout<<"false";
}