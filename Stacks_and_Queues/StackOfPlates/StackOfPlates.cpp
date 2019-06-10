#include<bits/stdc++.h>
using namespace std;

class Stacks
{
    vector<int> arr;
    vector<int> top;
    vector<int> next;
    int n;
    int size;
    public:
    Stacks(int n);
    void push(int item);
    bool isFull()
    {
        return (size == n);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int pop();
};

Stacks::Stacks(int n1)
{
    n = n1;
    top.push_back(-1);
    // next.push_back(1);
    size = 0;
}

void Stacks::push(int item)
{
    if(isFull())
    {
        cout<<"Creating new Stack and the size of the stack before creation is "<<top.size()<<"\n";
        cout<<"Top element of current stack is "<<arr[top[top.size() - 1]]<<"\n";
        size = 1;
        top.push_back(arr.size());
        next.push_back(next.size() + 1);
        arr.push_back(item);
        return;
    }
    size++;
    top[top.size() - 1] = top[top.size() - 1] + 1;
    next.push_back(next.size() + 1);
    arr.push_back(item);
}

int Stacks::pop()
{
    if(isEmpty())
    {
        cout<<"Deleting a stack, current stack size = "<<top.size()<<"\n";
        top.pop_back();
        int res = arr.back();
        top[top.size() - 1] -= 1;
        arr.pop_back();
        next.pop_back();
        if(arr.size() > 0)
            size = n;
        cout<<"Stack size after deletion = "<<top.size()<<"\n";
        return res;
    }

    int res = arr[top[top.size() - 1]];
    top[top.size() -1] = top[top.size() - 1] - 1;
    arr.pop_back();
    next.pop_back();
    size--;
    return res;
}

int main()
{
    int n = 2;
    Stacks st(n);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    cout<<st.pop()<<"\n";
    cout<<st.pop()<<"\n";
    cout<<st.pop()<<"\n";
    return 0;
}