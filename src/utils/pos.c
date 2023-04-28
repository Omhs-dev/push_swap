#include "../../includes/push_swap.h"

static void position(t_stack **stack)
{
    t_stack *temp;
    int i;

    temp = *stack;
    i = 0;
    while (tmp)
    {
        temp -> position = i;
        temp = temp -> next;
        i++;
    }
}

int get_the_lowest_index_position(t_stack **stack)
{
    t_stack *curr;
    int lowest_position;

    while (curr)
    {
        if (curr -> index < (*stack)-> index)
        {
            *stack = curr;
            lowest_position = 0;
        }
        if (curr -> index < (*stack)-> index)
            lowest_position++;
        curr = curr -> next;
    }
    *stack = curr;
    return (lowest_position);
}