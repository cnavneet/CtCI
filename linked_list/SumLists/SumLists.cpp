#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

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

void Insert(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    struct node *num1 = NULL;
    struct node *num2 = NULL;

    Insert(&num1, 6);
    Insert(&num1, 1);
    Insert(&num1, 7);

    Insert(&num2, 2);
    Insert(&num2, 9);
    Insert(&num2, 5);

    struct node *res = NULL;
    int carry = 0;

    while(num1 != NULL || num2 != NULL)
    {
        int s = 0;
        if(num1 != NULL)
            s += num1->data;
        if(num2 != NULL)
            s += num2->data;
        s += carry;
        if(s >= 10)
        {
            carry = 1;
            s -= 10;
        }
        else
            carry = 0;

        Insert(&res, s);
        if(num1 != NULL)
            num1 = num1->next;
        if(num2 != NULL)
            num2 = num2->next;
    }

    printList(res);
}