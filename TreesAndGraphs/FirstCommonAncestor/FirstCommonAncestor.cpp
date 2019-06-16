#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

int ans;
bool found;

Node* newNode(int data)
{
    Node *node = new Node();
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

int FindAncestor(Node *root, int a, int b)
{
    int leftAns = 0;
    if(root->left)
        leftAns=FindAncestor(root->left, a, b);
    int rightAns = 0;
    if(root->right)
        rightAns = FindAncestor(root->right, a, b);
    int temp = leftAns + rightAns;

    if(root->key == a || root->key == b)
        temp++;
    if(temp == 2)
    {
        if(!found)
        {
            ans = root->key;
            found = true;
        }
    }
    return temp;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->left = newNode(9);
    root->right->left->left = newNode(10);

    ans = 0;
    found = false;

    FindAncestor(root, 5, 6);

    if(found)
    {
        cout<<"Common Ancestor of 5 and 6 is: "<<ans<<"\n";
    }
    else
    {
        cout<<"Common ancestor of 5 and 6 doesn't exists\n";
    }
    return 0;
}