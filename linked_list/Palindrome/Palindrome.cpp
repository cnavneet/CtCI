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
        if(head->next != NULL)
            cout<<"->";
        head = head->next;
    }
}

bool isPalindrome(struct node *head)
{
    if(head == NULL)
        return true;
    if(head->next == NULL)
        return true;
    struct node *fast_ptr = head;
    struct node *slow_ptr = head;
    struct node *temp = head;

    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    struct node *new_head = NULL;
    while(slow_ptr != NULL)
    {
        Insert(&new_head, slow_ptr->data);
        slow_ptr = slow_ptr->next;
    }

    bool pali = true;
    while(new_head != NULL)
    {
        if(new_head->data != temp->data)
            pali = false;
        new_head = new_head->next;
        temp = temp->next;
    }
    return pali;
}

int main()
{
    struct node *head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 2);
    Insert(&head, 1);
    printList(head);
    cout<<"\n";
    if(isPalindrome(head))
        cout<<"Linked List is Palindrome\n";
    else
        cout<<"Linked List isn't Palindrome\n";
    return 0;
}