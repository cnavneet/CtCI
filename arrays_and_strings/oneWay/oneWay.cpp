#include<bits/stdc++.h>
using namespace std;

int EditDistance(string A, string B)
{
    int n = A.size();
    int m = B.size();
    int D[n+1][m+1];
    for(int i = 0;i<=n;++i)
        D[i][0] = i;
    for(int j = 0;j<=m;++j)
    D[0][j] = j;

    for(int j = 1;j<=m;++j)
    {
        for(int i = 1;i<=n;++i)
        {
            int insertion = D[i][j-1] + 1;
            int deletion = D[i-1][j] + 1;
            int match = D[i-1][j-1];
            int mismatch = D[i-1][j-1] + 1;

            if(A[i-1] == B[j-1])
            {
                D[i][j] = min(insertion, min(deletion, match));
            }
            else
            {
                D[i][j] = min(insertion, min(deletion, mismatch));
            }
        }
    }
    return D[n][m];
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;++i)
    {
        string A, B;
        cin>>A>>B;
        if(EditDistance(A, B) <= 1)
        {
            cout<<"true\n";
        }
        else
            cout<<"false\n";
    }
    return 0;
}