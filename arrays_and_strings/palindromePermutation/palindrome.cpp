#include<bits/stdc++.h>
using namespace std;

bool isPermutationPalindrome(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    map<char, int> m;
    for(int i = 0;i<s.length();++i)
        m[s[i]]++;

    int countOdd = 0;
    map<char, int>::iterator it;
    for(it = m.begin(); it!=m.end();++it)
    {
        if(it->second %2 != 0) 
            countOdd++;
    }

    if(s.length()%2==0 && countOdd > 0)
        return false;
    if(s.length()%2 != 0 && countOdd != 1)
        return false;

    return true;
}

int main()
{
    string s = "Tact Coa";
    if(isPermutationPalindrome(s))
        cout<<"True\n";
    else
        cout<<"False\n";

    return 0;
}