/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:48:16 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/27 16:06:20 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *stack_values(int num_arg, char **arr_str)
{
	t_stack *stack_a;
	long int nb;
	int i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < num_arg)
	{
		nb = ft_atoi(arr_str[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = create_new_stack((int)nb);
		else
			get_last_element(&stack_a, create_new_stack(nb));
		i++;
	}
	return (stack_a);
}
