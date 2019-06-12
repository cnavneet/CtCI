#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

vector<int> disc[MAXN];
bool visited[MAXN];
int n;
int Clock;
int Pre[MAXN];
int Post[MAXN];

void Previsit(int v)
{
    Pre[v] = Clock;
    Clock = Clock + 1;
}

void Postvisit(int v)
{
    Post[v] = Clock;
    Clock = Clock + 1;
}

void Explore(int v)
{
    visited[v] = true;

    Previsit(v);
    for(int i = 0;i<disc[v].size();++i)
    {
        if(!visited[disc[v][i]])
            Explore(disc[v][i]);
    }
    Postvisit(v);
}

void DFS()
{
    memset(visited, false, sizeof(visited));
    for(int i = 0;i<n;++i)
    {
        if(!visited[i])
            Explore(i);
    }
}

void TopologicalSort()
{
    DFS();
    vector<pair<int, int> > vec;
    for(int i = 0;i<n;++i)
    {
        vec.push_back(make_pair(Post[i], i));
    }
    sort(vec.rbegin(), vec.rend());
    for(int i = 0;i<vec.size();++i)
    {
        cout<<(char)('a' + vec[i].second)<<", ";
    }
    cout<<"\n";
}

int main()
{
    int m;
    cin>>n>>m;
    for(int i = 0;i<=n;++i)
        disc[i].clear();
    for(int i = 0;i<m;++i)
    {
        char a, b;
        cin>>a>>b;
        int u, v;
        u = a - 'a';
        v = b - 'a';
        disc[u].push_back(v);
    }
    Clock = 1;
    TopologicalSort();
}