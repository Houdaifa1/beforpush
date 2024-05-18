#include "push_swap.h"

void rrotate_two(stack **a)
{
    rrotate_a(a);
    rrotate_a(a);
}
int check_if_sorted(stack **a)
{
    stack *temp;
    int first_num;
    int second_num;

    temp = *a;
    first_num = temp->number;
    while (temp->next != NULL)
    {
        if (first_num > temp->next->number)
            return (1);
        temp = temp->next;
        first_num = temp->number;
    }
    return (0);
}

void sort_three_num(stack **a)
{
    int index;

    if ((*a)->next->next != NULL && (*a)->next->next->next == NULL && check_if_sorted(a) != 0)
    {
        numbers_index(a);
        index = get_big_num(a, 1);
        if (index == 1)
            rotate_a(a);
        else if (index == 2)
            rrotate_a(a);
        else if (index == 3)
            swap_a(a);
        if ((*a)->number > (*a)->next->number)
            swap_a(a);
    }
}
void sort_four_num(stack **a, stack **b)
{
    int index;

    if ((*a)->next->next->next != NULL && (*a)->next->next->next->next == NULL && check_if_sorted(a) != 0)
    {
        numbers_index(a);
        index = get_big_num(a, 1);
        if (index <= (4 / 2) + 1)
        {
            while (index > 1)
            {
                rotate_a(a);
                index--;
            }
            push_b(a, b);
        }
        else if (index == 4)
        {
            rrotate_a(a);
            push_b(a, b);
        }
        sort_three_num(a);
        push_a(b, a);
        rotate_a(a);
    }
}
void sort_five_num(stack **a, stack **b)
{
    int index;

    if ((*a)->next->next->next->next != NULL && (*a)->next->next->next->next->next == NULL)
    {
        numbers_index(a);
        index = get_big_num(a, 1);
        if (index <= (5 / 2) + 1)
        {
            while (index != 1)
            {
                rotate_a(a);
                index--;
            }
        }
        else if (index == 4)
            rrotate_two(a);
        else if (index == 5)
            rrotate_a(a);
        push_b(a, b);
        sort_four_num(a, b);
        push_a(b, a);
        rotate_a(a);
    }
}
int small_sort(stack **a, stack **b)
{
    int check;

    check = 0;
    if ((*a)->next->next != NULL && (*a)->next->next->next == NULL && check_if_sorted(a) != 0)
    {
        check = 1;
        sort_three_num(a);
    }
    else if ((*a)->next->next->next != NULL && (*a)->next->next->next->next == NULL && check_if_sorted(a) != 0)
    {
        check = 1;
        sort_four_num(a, b);
    }
    else if ((*a)->next->next->next->next != NULL && (*a)->next->next->next->next->next == NULL)
    {
        check = 1;
        sort_five_num(a, b);
    }
    return (check);
}

