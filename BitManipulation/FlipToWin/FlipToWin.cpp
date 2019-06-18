#include<bits/stdc++.h>
using namespace std;

string binaryToString(int n)
{
    string res = "";
    while(n)
    {
        if(n%2 == 1)
            res = res + '1';
        else
            res = res + '0';
        n = n/2;
    }
    return res;
}

int main()
{
    int n = 1775;
    string binary = binaryToString(n);
    int l = binary.length();
    int arr[l];
    for(int i = 0;i<l;++i)
        arr[i] = 0;
    if(binary[0] == '1')
        arr[0] = 1;
    for(int i = 1;i<l;++i)
    {
        if(binary[i] == '1')
        {
            arr[i] = arr[i-1] + 1;
        }
    }
    vector<int> vec;
    for(int i = 1;i<l;++i)
    {
        if(arr[i] == 0 && arr[i-1] != 0)
        {
            vec.push_back(arr[i-1]);
        }
    }
    if(arr[l-1] != 0)
    {
        vec.push_back(arr[l-1]);
    }

    int sum = INT_MIN;
    for(int i = 0;i<vec.size() - 1;++i)
    {
        sum = max(sum, vec[i] + vec[i+1] + 1);
    }
    cout<<sum<<"\n";
    return 0;
}