#include<bits/stdc++.h>
using namespace std;

class Stack
{
    vector<int> arr;
    vector<int> Minimum;
    int stIndex;
    int minIndex;
    public:
    Stack();
    void push(int val);
    int getMin();
    int pop();
};

Stack::Stack()
{
    stIndex = -1;
    minIndex = -1;
}

void Stack::push(int val)
{
    arr.push_back(val);
    stIndex++;
    if(minIndex >= 0)
    {
        if(Minimum[minIndex] > val)
        {
            Minimum.push_back(val);
            minIndex++;
        }
    }
    else
    {
        Minimum.push_back(val);
        minIndex++;
    }
}

int Stack::getMin()
{
    if(minIndex >= 0)
    {
        return Minimum[minIndex];
    }
    else
    {
        cout<<"No value Exists\n";
        return INT_MIN;
    }
}

int Stack::pop()
{
    if(stIndex >= 0)
    {
        int res = arr[stIndex];
        stIndex--;
        arr.erase(arr.begin() + (arr.size() - 1));
        if(Minimum[minIndex] == res)
        {
            Minimum.erase(Minimum.begin() + (Minimum.size() - 1));
            minIndex--;
        }
        return res;
    }
    else
    {
        cout<<"No value left to pop out\n";
        return INT_MIN;
    }
}

int main()
{
    Stack s;
    s.push(10);
    s.push(1);
    s.push(100);
    s.push(23);
    s.push(0);
    s.push(123);
    s.push(9);
    s.push(-1);

    cout<<s.getMin()<<"\n";
    cout<<"Popping out "<<s.pop()<<"\n";
    cout<<s.getMin()<<"\n";
    return 0;
}