/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:30:15 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/15 20:03:21 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//checks if the argument is a number
int	is_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + i] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

/*it checks if argument is a zero.
avoid anything else*/
static int	arg_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

//checks if the arguments are all numbers
int	is_parser_error(int arc)
{
	if (arc < 2)
		return (1);
	return (0);
}

int	correct_input(char **av)
{
	int	i;
	int	nb;

	nb = 0;
	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		nb += arg_zero(av[i]);
		i++;
	}
	if (nb > 1)
		return (0);
	return (1);
}
