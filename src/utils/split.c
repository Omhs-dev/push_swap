/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:40:18 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/15 19:17:19 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(const char *s, char dlm)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == dlm)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != dlm)
			i++;
	}
	return (count);
}

static char	*get_word(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * n +1);
	if (str == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!(str))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			str[k] = get_word(s + j, i - j);
			k++;
		}
	}
	str[k] = NULL;
	return (str);
}
