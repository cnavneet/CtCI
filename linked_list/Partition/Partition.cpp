#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void Insert(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node *head)
{
    while(head != NULL)
    {
        cout<<head->data;
        if(head -> next != NULL)
            cout<<"->";
        head = head->next;
    }
}

int main()
{
    struct node *head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 10);
    Insert(&head, 5);
    Insert(&head, 8);
    Insert(&head, 5);
    Insert(&head, 3);

    struct node *before = NULL;
    struct node *after = NULL;
    int x = 5;
    printList(head);
    cout<<"\n\n";
    while(head != NULL)
    {   
        if(head->data < x)
            Insert(&before, head->data);
        else
            Insert(&after, head->data);
        head = head -> next;
    }

    printList(before);
    cout<<"->";
    printList(after);
    cout<<"\n";
    return 0;
}