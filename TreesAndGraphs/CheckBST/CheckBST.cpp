#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node* newNode(int d)
{
    node *Node = new node() ;
    Node->data = d;
    Node->left = Node->right = NULL;
    return Node;
}

bool isBST(node *root, int Min, int Max)
{
    bool isLeftBalanced = true;
    bool isRightBalanced = true;

    if(root->left != NULL)
    {
        isLeftBalanced = isBST(root->left, Min, Max);
        isLeftBalanced = isLeftBalanced && (root->left->data < root->data);
    }
    if(root->right != NULL)
    {
        isRightBalanced = isBST(root->right, Min, Max);
        isRightBalanced = isRightBalanced && (root->right->data >= root->data);
    }

    return isLeftBalanced && isRightBalanced && root->data>=Min && root->data<Max;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->left = newNode(6);
    root->right->left->left = newNode(10);
    root->right->right = newNode(7);

    cout<<root->data<<"\n";
    cout<<root->left->data<<"\n";
    if(isBST(root->left, INT_MIN, root->data) && isBST(root->right, root->data, INT_MAX))
        cout<<"Tree is a BST!\n";
    else
        cout<<"Tree isn't a BST!\n";
    return 0;
}