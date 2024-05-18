#include "push_swap.h"

void swap_a(stack **a)
{
    stack *tempa;
    stack *tempb;
    stack *tempc;

    stack *curr = *a;
    if (curr && curr->next != NULL)
    {
        tempa = curr;
        tempb = curr->next;
        tempc = curr->next->next;
        tempa->index = 1;
        tempb->index = 0;
        tempa->next = tempc;
        tempb->next = tempa;
        *a = tempb;
        write(1, "sa\n", 3);
    }
}
void swap_b(stack **a)
{
    stack *tempa;
    stack *tempb;
    stack *tempc;

    stack *curr = *a;
    if (curr && curr->next != NULL)
    {
        tempa = curr;
        tempb = curr->next;
        tempc = curr->next->next;
        tempa->index = 1;
        tempb->index = 0;
        tempa->next = tempc;
        tempb->next = tempa;
        *a = tempb;
        write(1, "sb\n", 3);
    }
}

void ss(stack **a, stack **b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
}
void push_a(stack **a, stack **b)
{
    if (*a)
    {
        stack *new_node = (stack *)malloc(sizeof(stack));
        stack *top_a = (*a);
        new_node->number = top_a->number;
        new_node->index = 0;
        new_node->next = *b;
        *b = new_node;
        *a = top_a->next;
        free(top_a);
        write(1, "pa\n", 3);
    }
}
void push_b(stack **a, stack **b)
{
    stack *new_node;
    stack *top_a;

    if (*a)
    {
        new_node = (stack *)malloc(sizeof(stack));
        top_a = (*a);
        new_node->number = top_a->number;
        new_node->index = 0;
        new_node->next = *b;
        *b = new_node;
        *a = top_a->next;
        free(top_a);
        write(1, "pb\n", 3);
    }
}

void rotate_a(stack **a)
{
    stack *topa;
    stack *last;

    if ((*a) && (*a) -> next != NULL)
    {
        topa = (*a)->next;
        last = (*a);
        (*a) = topa;
        while (topa->next != NULL)
        {
            topa = topa->next;
        }
        topa->next = last;
        last->next = NULL;
        write(1, "ra\n", 3);

    }
}
void rotate_b(stack **a)
{
    stack *topa;
    stack *last;

    if ((*a) && (*a) -> next != NULL)
    {
        topa = (*a)->next;
        last = (*a);
        (*a) = topa;
        while (topa->next != NULL)
        {
            topa = topa->next;
        }
        topa->next = last;
        last->next = NULL;
        write(1, "rb\n", 3);

    }
}

void rrotate_a(stack **a)
{
    stack *temp1;
    stack *temp2;

    temp1 = *a;
    if (temp1 && temp1 -> next != NULL)
    {
        while (temp1 -> next -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;
        temp1 -> next = NULL;
        temp2 -> next = *a;
        *a = temp2;
        write(1, "rra\n", 4);
    }
}

void rrotate_b(stack **a)
{
    stack *temp1;
    stack *temp2;

    temp1 = *a;
    if (temp1 && temp1 -> next != NULL)
    {
        while (temp1 -> next -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;
        temp1 -> next = NULL;
        temp2 -> next = *a;
        *a = temp2;
        write(1, "rrb\n", 4);
    }
}

void free_list(stack **list)
{
    stack *temp;
    while (*list != NULL)
    {
        temp = (*list) -> next;
        free(*list);
        *list = temp;
    }

}