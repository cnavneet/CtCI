#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> vec;
    string s;
    cin>>s;
    while(s != "")
    {
        vec.push_back(s);
        cin>>s;
        if(s[0] - '0' >=0 && s[0] - '0' <= 9)
            s = "";
    }

    for(int i = 0;i<vec.size() - 1;++i)
    {
        cout<<vec[i]<<"%20";
    }
    cout<<vec[vec.size() - 1]<<"\n";
    return 0;
}