/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:05:50 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/27 01:13:42 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *stack_cntn)
{
	t_node	*temp;
	t_node	*temp2;
	int swp;
	int count;

	temp = s_cntn;
	swp = 0;
	count = 0;
	if (stack_cntn == NULL || stack_cntn -> next == NULL)
		return ;
	while (temp != NULL && count < 1)
	{
		temp2 = temp -> next;
		swp = temp -> data;
		temp -> data = temp -> next -> data;
		temp -> next -> data = swp;
		temp = temp2;
		count++;
	}
}

void swap_a(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void swap_b(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}