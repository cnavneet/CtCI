#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

vector<int> inorder;
vector<int> postorder;

Node* newNode(int data)
{
    Node *node = new Node();
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

void InorderTraversal(Node *root)
{
    if(root == NULL)
        return;
    InorderTraversal(root->left);
    cout<<root->key<<" ";
    InorderTraversal(root->right);
}

void PostOredrTraversal(Node *root)
{
    if(root == NULL)
        return;
    PostOredrTraversal(root->left);
    PostOredrTraversal(root->right);
    cout<<root->key<<" ";
}

int main()
{
    Node *node = newNode(2);
    node->left = newNode(1);
    node->right = newNode(3);

    InorderTraversal(node);
    cout<<"\n";
    PostOredrTraversal(node);
    return 0;
}