# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack_a
{
    int                 number;
    int                 index;
    int                 cost;
    int                 target_num_index;
    struct s_stack_a    *next;
} stack;

typedef struct s_infos
{
    int                 index;
    int                 check_a;
    int                 check_b;
    int                 count_a;
    int                 count_b;
    int                 target_num_index;

} t_infos;

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_free_arr(char **arr, int e);
long    ft_atoi(char *str, char **arr);
void    swap_a(stack **a);
void    swap_b(stack **a);
void    ss(stack **a, stack **b);
void    push_a(stack **a, stack **b);
void    push_b(stack **a, stack **b);
void    rotate_a(stack **a);
void    rotate_b(stack **a);
void    rr(stack **a, stack **b);
void    rrotate_a(stack **a);
void    rrotate_b(stack **a);
void    rrr(stack **a, stack **b);
void    free_list(stack **list);
void    numbers_index(stack **a);
int     send_min(stack **a, stack **b, int count);
void send_max(stack **a, stack **b);
int     count_stack(stack **a);
void    divide_stack(stack **a, stack **b);
void    send_to_b(int index, int count, stack **a, stack **b);
int     get_small_num(stack **a, int i);
int     get_big_num(stack **a, int i);
int    small_sort(stack **a, stack **b);
void    find_target(stack **a, stack **b);
int count_stack(stack **a);
void push_two_numbers(stack **a, stack **b);
void rotate_the_stack(int index, int count, stack **a, stack **b,  char c);
void find_target_b(stack **b, stack **a);
void bring_min_top(int count, int index, stack **b);


# endif