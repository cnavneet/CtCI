#include<bits/stdc++.h>
using namespace std;

int *tree;
int *Left;
int *Right;
int *Parent;
int *height;
int curr;

int Find(int k, int r)
{
    if(tree[r] == k)
        return r;
    else if(tree[r] > k)
    {
        if(Left[r] != -1)
            return Find(k, Left[r]);
        return r;
    }
    else if(tree[r] < k)
    {
        if(Right[r] != -1)
            return Find(k, Right[r]);
        return r;
    }
}

int LeftDescendant(int n)
{
    if(Left[n] == -1)
        return n;
    else
        return LeftDescendant(Left[n]);
}

int RightAncestor(int n)
{
    if(Parent[n] == -1)
        return n;
    if(tree[n] < tree[Parent[n]])
        return Parent[n];
    else
        return RightAncestor(Parent[n]);
}

int Next(int n)
{
    if(Right[n] != -1)
        return LeftDescendant(Right[n]);
    else
        return RightAncestor(n);
}

void Insert(int k, int r)
{
    int p = Find(k ,r);
    curr++;
    if(tree[p] > k)
        Left[p] = curr;
    else
        Right[p] = curr;
    tree[curr] = k;
}

void RotateRight(int x)
{
    int p = Parent[x];
    int y = Left[x];
    int b = Right[y];

    Parent[y] = p;
    if(tree[p] > tree[y])
        Left[p] = y;
    else
        Right[p] = y;
    Parent[x] = y;
    Right[y] = x;
    Parent[b] = x;
    Left[x] = b;
}

void RotateLeft(int x)
{
    int p = Parent[x];
    int y = Right[x];
    int b = Left[y];

    Parent[y] = p;
    if(tree[p] > tree[y])
        Left[p] = y;
    else
        Right[p] = y;
    
    Parent[x] = y;
    Left[y] = x;

    Parent[b] = x;
    Right[x] = b;
}

void AdjustHeight(int n)
{
    if(Left[n] != -1 && Right[n] == -1)
    {
        height[n] = 1 + height[Left[n]];
    }
    else if(Left[n] == -1 && Right[n] != -1)
    {
        height[n] = 1 + height[Right[n]];
    }
    else if(Left[n] != -1 && Right[n] != -1)
    {
        height[n] = 1 + max(height[Left[n]], height[Right[n]]);
    }
}

void RebalanceLeft(int n)
{
    int m = Right[n];
    if(height[Left[m]] > height[Right[m]])
        RotateRight(m);
    RotateLeft(n);
    AdjustHeight(Right[Right[n]]);
    AdjustHeight(Right[n]);
    AdjustHeight(Left[n]);
    AdjustHeight(n);
}

void RebalanceRight(int n)
{
    int m = Left[n];
    if(height[Left[m]] < height[Right[m]])
        RotateLeft(m);
    RotateRight(n);
    AdjustHeight(Left[Left[n]]);
    AdjustHeight(Left[n]);
    AdjustHeight(Right[n]);
    AdjustHeight(n);
}

void Rebalance(int n)
{
    int p = Parent[n];
    if(height[Left[n]] > height[Right[n]] + 1)
        RebalanceRight(n);
    if(height[Right[n]] > height[Left[n]] + 1)
        RebalanceLeft(n);
    AdjustHeight(n);
    if(p!=-1)
        Rebalance(p);
}

void AVLInsert(int k ,int r)
{
    Insert(k, r);
    int n = Find(k, r);
    Rebalance(n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    tree = new int[n];
    Left = new int[n];
    Right = new int[n];
    Parent = new int[n];
    height = new int[n];
    int r = 0;
    curr = -1;
    for(int i = 0;i<n;++i)
    {
        Left[i] = -1;
        Right[i] = -1;
        Parent[i] = -1;
        height[i] = 1;
    }

    for(int i = 0;i<n;++i)
    {
        AVLInsert(arr[i], r);
    }
    return 0;
}