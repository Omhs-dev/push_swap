/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 01:16:02 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/27 01:26:48 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack *stack_cntn)
{	
	t_node	*temp;
	int swp;

	temp = stack_cntn;
	swp = 0;
	while (temp != NULL && temp -> next != NULL)
	{
		swp = temp -> data;
		temp -> data = temp -> next -> data;
		temp -> next -> data = swp;
		temp = temp -> next;
	}
}

void rotate_a(t_stack **stack_a)
{
	rotate(*stack_a);
	write(1, "ra\n", 3);
}

void rotate_b(t_stack **stack_b)
{
	rotate(*stack_b);
	write(1, "rb\n", 3);
}

void rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(*stack_a);
	rotate(*stack_b);
	write(1, "rr\n", 3);
}
