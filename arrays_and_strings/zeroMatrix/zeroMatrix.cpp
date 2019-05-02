#include<bits/stdc++.h>
using namespace std;

int **arr;
int m, n;

int main()
{
    cin>>m>>n;
    arr = new int*[m];
    vector<int> row;
    vector<int> col;
    for(int i = 0; i<m;++i)
    {
        arr[i] = new int[n];
        for(int j = 0;j<n;++j)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 0)
            {
                if(find(row.begin(), row.end(), i) == row.end())
                    row.push_back(i);
                if(find(col.begin(), col.end(), j) == col.end())
                    col.push_back(j);
            }
        }
    }

    for(int i = 0;i<row.size();++i)
    {
        for(int j = 0;j<n;++j)
            arr[row[i]][j] = 0;
    }

    for(int i = 0;i<col.size();++i)
    {
        for(int j = 0;j<m;++j)
            arr[j][col[i]] = 0;
    }

    for(int i = 0;i<m;++i)
    {
        for(int j = 0;j<n;++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}