#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
};

void Insert(struct node **head_ref, char new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(struct node *head)
{
    while(head != NULL)
    {
        cout<<head->data;
        if(head->next != NULL)
            cout<<"->";
        head = head->next;
    }
    cout<<"\n";
}

struct node* deleteMid(struct node *head)
{
    if(head == NULL)
        return NULL;
    if(head -> next == NULL)
    {
        delete head;
        return NULL;
    }

    struct node *slow_ptr = head;
    struct node *fast_ptr = head -> next;

    struct node *prev;
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr -> next -> next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    prev->next = slow_ptr->next;
    delete slow_ptr;

    return head;
}

int main()
{
    struct node *head = NULL;
    Insert(&head, 'f');
    Insert(&head, 'e');
    Insert(&head, 'd');
    Insert(&head, 'c');
    Insert(&head, 'b');
    Insert(&head, 'a');

    print_list(head);

    head = deleteMid(head);

    print_list(head);
    return 0;
}