#include "push_swap.h"

// void *count_best_push_b(int index_b, int index_a, int count_a, int count_b, int reset, t_infos *infos)
// {
//     static int small_cost;
//     static int node_index;
//     static int target_node_index;
//     int check_a;
//     int check_b;
//     stack *theone;

//     check_a = 0;
//     check_b = 0;
//     if (index_a > (count_a / 2) + 1)
//     {
//         index_a = count_a - index_a + 2;
//         check_a = 1;
//     }
//     if (index_b > (count_b / 2) + 1)
//     {
//         index_b = count_b - index_b + 2;
//         check_b = 1;
//     }
//     if (reset == 0)
//     {
//         small_cost = index_a + index_b - 2;
//         if (check_a == 1)
//             index_a = (count_a + 2) - index_a;
//         node_index = index_b;
//         if (check_b == 1)
//             index_b = (count_b + 2) - index_b;
//         target_node_index = index_a;
//     }
//     if (index_a + index_b - 2 < small_cost)
//     {
//         small_cost = index_a + index_b - 2;
//         if (check_a == 1)
//             index_a = (count_a + 2) - index_a;
//         node_index = index_b;
//         if (check_b == 1)
//             index_b = (count_b + 2) - index_b;
//         target_node_index = index_a;
//     }
//     infos->index = node_index;
//     infos->target_num_index = target_node_index;
//     infos->cost = small_cost;
// }

// int found_the_target_b(int b_number, stack *a, int big_num_index)
// {
//     int check;
//     int target_num;
//     int target_num_index;

//     target_num = a->number;
//     target_num_index = a->index;
//     check = 0;
//     while (a->next != NULL)
//     {
//         a = a->next;
//         if (target_num < b_number)
//         {
//             target_num = a->number;
//             target_num_index = a->index;
//         }
//         else if (a->number > b_number && a->number < target_num)
//         {
//             target_num = a->number;
//             target_num_index = a->index;
//             check = 1;
//         }
//     }
//     if (check == 0 && target_num < b_number)
//         target_num_index = big_num_index;
//     return (target_num_index);
// }

// void push_to_a(int index_b, int index_a, stack **a, stack **b)
// {
//     int count_a;
//     int count_b;

//     count_a = count_stack(a);
//     count_b = count_stack(b);
//     rotate_the_stack(index_a, count_a, a,b, 'a');
//     rotate_the_stack(index_b, count_b, a,b, 'b');
//     push_a(b, a);
    
// }
// void find_target_b(stack **b, stack **a)
// {
//     stack *tempa;
//     stack *tempb;
//     stack *theone;
//     int i;
//     int target_num_index;
//     int count_a;
//     int count_b;
//     int reset;
//     int small_num_index;
//     t_infos infos;

//     tempb = *b;
//     tempa = *a;
//     count_b = count_stack(b);
//     count_a = count_stack(a);
//     small_num_index = get_small_num(a, 1);
//     reset = 0;
//     i = 0;
//     while (i < count_b)
//     {
//         tempa = *a;
//         target_num_index = found_the_target_b(tempb->number, tempa, small_num_index);
//         //printf("%d                %d\n", tempb->number ,target_num_index);
//         theone = count_best_push_b(tempb->index, target_num_index, count_b, count_a, reset, &infos);
//         tempb = tempb->next;
//         reset = 1;
//         i++;
//     }
//     //printf("%d                %d                %d\n", infos.index ,infos.target_num_index, infos.cost);
//     push_to_a(infos.index, infos.target_num_index, a, b);
// }

// 1 0                == 1            2  cost 1
// 2 -5               == 2            2 cost 2
// 3 3                == 2
// 4 -6
// 5 -8
// 6 9
// 7 5
// 8 2
// 9 8
// 10 2

// cost = 1 + 2 - 2 = 1
// cost = 2 + 2 - 2 = 2
// cost = 3 + 2 - 2 = 3

// if (count / 2 + 1 == index_a)   == index = count - 10 - index + 2;

// 1 8
// 2 -9
#include "push_swap.h"



// 1 0                == 1            2  cost 1
// 2 -5               == 2            2 cost 2
// 3 3                == 2
// 4 -6
// 5 -8
// 6 9
// 7 5
// 8 2
// 9 8
// 10 2

// cost = 1 + 2 - 2 = 1
// cost = 2 + 2 - 2 = 2
// cost = 3 + 2 - 2 = 3

// if (count / 2 + 1 == index_a)   == index = count - 10 - index + 2;

// 1 8
// 2 -9
