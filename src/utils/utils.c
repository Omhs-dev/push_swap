/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 05:35:40 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/27 15:33:21 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//changes
void free_stack(t_stack **stack)
{
	t_stack *tmp;

	//some change
	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)-> next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

//changes
void exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

