#include "push_swap.h"

void check_chars(char *str, int f)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-' || str[i] == '+'))
        {
            write(2, "Error\n", 6);
            if (f == 1)
                free(str);
            exit(1);
        }
        i++;
    }
}
void check_max_min(char **arr)
{
    int i;
    long num;

    i = 0;
    while (arr[i])
    {
        num = ft_atoi(arr[i], arr);
        if (num > INT_MAX || num < INT_MIN)
            ft_free_arr(arr, 1);
        i++;
    }
}

void check_doublication(char **arr)
{
    int curr;
    int i;
    int count;

    count = 0;
    while (arr[count] != NULL)
        count++;
    curr = 0;
    while (curr < count)
    {
        i = 0;
        while (arr[i] != NULL)
        {
            if (i == curr)
                i++;
            else if (i != curr)
            {
                if (ft_atoi(arr[curr], arr) == ft_atoi(arr[i], arr))
                    ft_free_arr(arr, 1);
                i++;
            }
        }
        curr++;
    }
}

void insert_in_a(char **arr, stack **a)
{
    stack *curr;
    int num;
    int i;
    int count;

    i = 0;
    count = 0;
    curr = malloc(sizeof(stack));
    (*a) = curr;
    while (arr[count] != NULL)
        count++;
    while (i < count)
    {
        curr->number = ft_atoi(arr[i], arr);
        if (i != count - 1)
            curr->next = malloc(sizeof(stack));
        curr = curr->next;
        i++;
    }
    curr = NULL;
}

int check_sort(char **arr)
{
    int i;
    int count;
    int check;
    int j;
    int t;

    i = 0;
    t = 1;
    count = 0;
    check = 0;
    while (arr[count])
        count++;
    while (arr[i] != NULL)
    {
        j = t;
        while (j < count)
        {
            if (ft_atoi(arr[i], arr) > ft_atoi(arr[j], arr))
                check = 1;
            j++;
        }
        i++;
        t++;
    }
    return (check);
}
int check_numbers(char *str)
{
    int i;
    int check;

    i = 0;
    check = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            check = 1;
        i++;
    }
    if (check == 0)
        return (1);
    return (0);
}
void check_len_zero(char **arr)
{
    int i;
    int j;
    int len;

    i = 0;
    while (arr[i] != NULL)
    {
        j = 0;
        len = 0;
        if (check_numbers(arr[i]) == 1)
            ft_free_arr(arr, 1);
        if (arr[i][0] == '-' || arr[i][0] == '+')
            j++;
        while (arr[i][j] && arr[i][j] == '0')
            j++;
        while (arr[i][j])
        {
            j++;
            len++;
            if (len > 11)
                ft_free_arr(arr, 1);
        }
        i++;
    }
}
void numbers_index(stack **a)
{
    int i;
    stack *curr;

    i = 1;
    curr = *a;
    while (curr != NULL)
    {
        curr->index = i;
        curr = curr->next;
        i++;
    }
}

int index_small(stack **a)
{
    int index;
    int small_num;
    stack *curr;

    curr = *a;
    index = 1;
    small_num = curr->number;
    while (curr->next != NULL)
    {
        curr = curr->next;
        if (small_num > curr->number)
        {
            small_num = curr->number;
            index = curr->index;
        }
    }
    return (index);
}

int main(int arc, char **arv)
{
    char **allargs;
    char *argsoneline;
    int i;
    int f;
    int j;
    char *temp;
    int count;
    stack *a;
    stack *b;

    temp = NULL;
    b = NULL;
    a = NULL;
    if (arc == 1)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    else if (arc == 2)
        temp = arv[1];
    else if (arc > 2)
    {
        i = 1;
        f = 0;
        while (i <= arc - 1)
        {
            argsoneline = ft_strjoin(temp, arv[i]);
            free(temp);
            temp = argsoneline;
            i++;
            f = 1;
        }
    }
    check_chars(temp, f);
    allargs = ft_split(temp, ' ');
    if (allargs[1] == NULL)
        ft_free_arr(allargs, 1);
    if (f == 1)
        free(temp);
    check_len_zero(allargs);
    check_max_min(allargs);
    check_doublication(allargs);
    int test = check_sort(allargs);
    if (test == 0)
    {
        ft_free_arr(allargs, 0);
        exit(0);
    }
    insert_in_a(allargs, &a);
    int l = small_sort(&a, &b);
    j = 0;
    if (l == 0)
    {
        push_b(&a, &b);
        push_b(&a, &b);
        count = count_stack(&a);
        while (j < count)
        {
            numbers_index(&a);
            numbers_index(&b);
            find_target(&a, &b);
            j++;
        }
        j = 0;
        count = count_stack(&b);
        while (j < count)
        {
            numbers_index(&a);
            numbers_index(&b);
            send_max(&a, &b);
            j++;
        }
    }
}
