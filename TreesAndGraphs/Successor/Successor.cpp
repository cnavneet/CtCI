#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

int key[MAXN];
int LeftChild[MAXN];
int RightChild[MAXN];
int Parent[MAXN];
int height[MAXN];
int size;
int root;

int AdjustHeight(int n)
{
    if(LeftChild[n] != -1 && RightChild[n] != -1)
        height[n] = 1 + max(height[LeftChild[n]], height[RightChild[n]]);
    else if(LeftChild[n] == -1 && RightChild[n] != -1)
        height[n] = 1 + height[RightChild[n]];
    else if(RightChild[n] == -1 && LeftChild[n] != -1)
        height[n] = 1 + height[LeftChild[n]];
    else
        height[n] = 0;
}


int Find(int k, int r)
{
    if(key[r] == k)
        return r;
    else if(key[r] > k)
    {
        if(LeftChild[r] != -1)
            return Find(k, LeftChild[r]);
        return r;
    }
    else if(key[r] < k)
    {
        if(RightChild[r] != -1)
            return Find(k, RightChild[r]);
        return r;
    }
}

void Insert(int k, int r)
{
    int n = Find(k, r);
    if(key[n] != k)
    {
        if(key[n] > k)
        {
            if(n!=size)
                LeftChild[n] = size;
        }
        else
        {
            if(n!=size)
                RightChild[n] = size;
        }
        if(n!=size)
            Parent[size] = n;
        key[size] = k;
        size++;
    }
}

void RotateLeft(int n)
{
    int p = Parent[n];
    int r = RightChild[n];
    if(p!=-1)
        LeftChild[p] = r;
    else
        root = r;
    Parent[r] = p;
    Parent[n] = r;
    if(LeftChild[r] != -1)
    {
        int l = LeftChild[r];
        Parent[l] = n;
        RightChild[n] = l;
    }
    RightChild[n] = LeftChild[r];
    LeftChild[r] = n;
}

void RotateRight(int n)
{
    int p = Parent[n];
    int l = LeftChild[n];
    if(p!=-1)
        RightChild[p] = l;
    else
        root = l;
    Parent[l] = p;
    Parent[n] = l;
    if(RightChild[l] != -1)
    {
        int r = RightChild[l];
        Parent[r] = n;
        LeftChild[n] = r;
    }

    LeftChild[n] = RightChild[l];
    RightChild[l] = n;
}

void RebalanceLeft(int n)
{
    int m = RightChild[n];
    if(height[LeftChild[m]] > height[RightChild[m]])
        RotateRight(m);
    RotateLeft(n);
    AdjustHeight(RightChild[RightChild[n]]);
    AdjustHeight(RightChild[n]);
    AdjustHeight(LeftChild[n]);
    AdjustHeight(n);
}

void RebalanceRight(int n)
{
    int m = LeftChild[n];
    if(height[RightChild[m]] > height[LeftChild[m]])
        RotateLeft(m);
    RotateRight(n);
    AdjustHeight(LeftChild[LeftChild[n]]);
    AdjustHeight(LeftChild[n]);
    AdjustHeight(RightChild[n]);
    AdjustHeight(n);
}

void Rebalance(int n)
{
    int p = Parent[n];
    int hl, hr;
    if(LeftChild[n] == -1)
        hl = 0;
    else
        hl = height[LeftChild[n]];
    if(RightChild[n] == -1)
        hr = 0;
    else
        hr = height[RightChild[n]];
    if(hl > hr + 1)
        RebalanceRight(n);
    if(hr > hl + 1)
        RebalanceLeft(n);
    AdjustHeight(n);
    if(p!=-1)
        Rebalance(p);
}

void AVLInsert(int k, int r)
{
    Insert(k, r);
    int n = Find(k, r);
    Rebalance(n);
}

int LeftDescendant(int n)
{
    if(LeftChild[n] != -1)
        return n;
    else
        return LeftDescendant(LeftChild[n]);
}

int RightAncestor(int n)
{
    if(Parent[n] == -1)
        return -1;
    if(key[n] < key[Parent[n]])
        return Parent[n];
    else
        return RightAncestor(Parent[n]);
}

int Next(int n)
{
    if(RightChild[n] != -1)
        return LeftDescendant(RightChild[n]);
    else
        return RightAncestor(n);
}

int main()
{
    int n = 10;
    for(int i = 0;i<=n;++i)
    {
        key[i] = INT_MAX;
        LeftChild[i] = -1;
        RightChild[i] = -1;
        Parent[i] = -1;
        height[i] = 0;
    }
    size = 0;
    root = 0;
    for(int i = 0;i<n;++i)
    {
        if(size == 0)
        {
            key[size] = i;
            size++;
        }
        else
        {
            AVLInsert(i, root);
        }
    }

    for(int i = 0;i<n;++i)
    {
        cout<<"Next element of "<<i<<" is: "<<Next(i)<<"\n";
    }
    return 0;
}