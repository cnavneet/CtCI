#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int getData(struct node *head, int k)
{
    int Count = 0;
    struct node *ptr;
    while(head != NULL)
    {
        Count++;
        if(Count == k)
        {
            ptr = head;
        }
        else if(Count > k + 1)
        {
            ptr = ptr -> next;
        }
        head = head->next;
    }
    return ptr->data;
}

void printList(struct node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main()
{
    struct node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    printList(head);
    cout<<getData(head, 2);
    return 0;
}