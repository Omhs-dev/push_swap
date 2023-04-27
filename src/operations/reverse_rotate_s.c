/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:03:03 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/27 02:24:25 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack **stack_cntn)
{
	t_stack *tmp;
	t_stack *tmp2;

	if ((*stack_cntn)-> next != NULL)
		return ;
	tmp2 = *stack_cntn;
	while (tmp2 -> next -> next != NULL)
		tmp2 = tmp2 -> next;
	tmp = tmp2 -> next;
	tmp -> next = *stack_cntn;
	*stack_cntn = tmp;
	tmp2 -> next = NULL;
}

void reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 3);
}

void reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 3);
}

void reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 3);
}
