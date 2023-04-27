/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    stack_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:28:02 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/27 16:05:54 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *create_new_stack(int data)
{
	t_stack *new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new -> data = data;
	new -> a = -1;
	new -> b = -1;
	new -> index = 0;
	new -> position = -1;
	new -> pos_target = -1;
	new -> next = NULL;
	return (new);
}

t_stack *get_last_element(t_stack *stack)
{
	while (stack && stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

t_stack *get_beforelast_element(t_stack *stack)
{
	while (stack && stack -> next && stack -> next -> next != NULL)
		stack = stack -> next;
	return (stack);
}
