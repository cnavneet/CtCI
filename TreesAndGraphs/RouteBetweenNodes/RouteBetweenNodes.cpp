#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000

vector<int> disc[MAXN];
bool visited[MAXN];

void Explore(int u)
{
    visited[u] = true;
    for(int i = 0;i<disc[u].size();++i)
    {
        if(!visited[disc[u][i]])
            Explore(disc[u][i]);
    }
}

void DFS(int u)
{
    memset(visited, false, sizeof(visited));
    Explore(u);
}

bool RouteExists(int u, int v)
{
    DFS(u);
    bool check1 = visited[v];
    DFS(v);
    bool check2 = visited[u];
    if(check1 || check2)
        return true;
    return false;
}

int main()
{
    int n = 10;
    int m = 9;
    for(int i = 1;i<=n;++i)
        disc[i].clear();
    disc[1].push_back(2);
    disc[1].push_back(2);
    disc[2].push_back(4);
    disc[2].push_back(5);
    disc[3].push_back(6);
    disc[3].push_back(7);
    disc[4].push_back(8);
    disc[5].push_back(9);
    disc[6].push_back(10);

    if(RouteExists(2, 9))
    {
        cout<<"Route exists between nodes 2 and 9\n";
    }
    else
    {
        cout<<"Route doesn't exists between nodes 2 and 9\n";
    }

    if(RouteExists(8, 9))
    {
        cout<<"Route exists between nodes 8 and 9\n";
    }
    else
    {
        cout<<"Route doesn't exists between nodes 8 and 9\n";
    }

    return 0;
}