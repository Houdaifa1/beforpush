#include "push_swap.h"


int get_small_num(stack **a, int i)
{
    stack *temp;
    int small_num;
    int num_index;

    temp = *a;
    small_num = temp -> number;
    num_index = 1;
    while (temp -> next != NULL)
    {
        temp = temp->next;
        if (temp->number < small_num)
        {
            small_num = temp-> number;
            num_index = temp-> index;
        }
    }
    if (i == 1)
        return (num_index);
    else
        return(small_num);
}
int get_big_num(stack **a, int i)
{
    stack *temp;
    int big_num;
    int num_index;

    temp = *a;
    big_num = temp -> number;
    num_index = 1;
    while (temp -> next != NULL)
    {
        temp = temp->next;
        if (temp->number > big_num)
        {
            big_num = temp-> number;
            num_index = temp-> index;
        }
    }
    if (i == 1)
        return (num_index);
    else
        return (big_num);

}
int count_stack(stack **a)
{
    int count;
    stack *temp;

    count = 0;
    temp = *a;
    if (temp)
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
    return (count);
}

void bring_min_top(int count, int index, stack **b)
{
 
    if (index <= count / 2 + 1)
    {
        while(index > 1)
        {
            rotate_b(b);
            index--;
        }
    }
    else
    {
        while (index <= count)
        {
            rrotate_b(b);
            index++;
        }
    }
}

void check_b(stack *a, stack **b)
{
    stack *temp;
    int big_num;
    int small_num;
    int count;
    int index;
    int check;

    temp = *b;
    check = 0;
    if (!*b)
        return;
    big_num = get_big_num(b, 2);
    small_num = get_small_num(b, 2);
    if (a -> number > big_num || a-> number < small_num)
    {
        numbers_index(b);
        index = get_small_num(b, 1);
        count = count_stack(b);
        bring_min_top(count, index, b);
    }
}

void    send_to_b(int index, int count, stack **a, stack **b)
{
    if (index <= count / 2 + 1)
    {
        while(index > 1)
        {
            rotate_a(a);
            index--;
        }
        check_b((*a), b);
        push_b(a ,b);
    }
    else
    {
        while (index <= count)
        {
            rrotate_a(a);
            index++;
        }
        check_b((*a), b);
        push_b(a, b);
    }

}

int send_min(stack **a, stack **b, int count)
{
    int first_value;
    int first_index;
    int second_value;
    int second_index;
    stack *temp;

    temp = *a;
    first_value = temp->number;
    first_index = 1;
    while (temp->index < 50)
    {
        temp = temp->next;
        if (temp->number < first_value)
        {
            first_value = temp->number;
            first_index = temp->index;
        }
    }
    if (count < 50)
    {
        while (temp->index < 51)
            temp = temp->next;
    }
    else 
    {
            while (temp->index < (count - 50))
                temp = temp->next;
    }
    second_index = temp->index;
    second_value = temp->number;
    while (temp->index < count)
    {
        temp = temp->next;
        if (temp->number < second_value)
        {
            second_value = temp->number;
            second_index = temp->index;
        }
    }
    if (first_index == (count + 1 - second_index))
    {
        if (first_value < second_value)
            return (first_index);
        else if (first_value > second_value)
            return (second_index);
    }
    else if (first_index != (count + 1 - second_index))
    {
        if (first_index < ( count + 1 - second_index))
            return (first_index);
        else if (first_index > ( count + 1 - second_index))
            return (second_index);
    }
}

void send_min_to_b(int count, stack **a, stack **b)
{
    int index;


    index = get_small_num(a, 1);
    if (index <= count / 2 + 1)
    {
        while(index > 1)
        {
            rotate_a(a);
            index--;
        }
        check_b((*a), b);
        push_b(a, b);
    }
    else 
    {
        while(index <= count)
        {
            rrotate_a(a);
            index++;
        }
        check_b((*a), b);
        push_b(a, b);
    }
}

void send_max(stack **a, stack **b)
{
    int index;
    int count;

    index = get_big_num(b, 1);
    count = count_stack(b);
    if (index <= count / 2)
    {
        while(index > 1)
        {
            rotate_b(b);
            index--;
        }
        push_a(b, a);
    }
    else
    {
        while (index <= count)
        {
            rrotate_b(b);
            index++;
        }
        push_a(b, a);
    }
}

void divide_stack(stack **a, stack **b)
{
    int stack_count;
    int index;

    stack_count = count_stack(a);
    while (stack_count > 50)
    {
        numbers_index(a);
        stack_count = count_stack(a);
        index = send_min(a, b, stack_count);
        send_to_b(index, stack_count, a, b);
    }
    while (stack_count > 1)
    {
        numbers_index(a);
        stack_count = count_stack(a);
        send_min_to_b(stack_count, a, b);
    }
    while (*b)
    {
        numbers_index(b);
        send_max(a, b);
    }
}
