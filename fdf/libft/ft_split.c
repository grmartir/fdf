/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:23 by grmartir          #+#    #+#             */
/*   Updated: 2023/02/04 15:53:39 by grmartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *str, char c)
{
	int	i;
	int	count;
	int	prev;

	i = 0;
	count = 0;
	prev = 1;
	while (str[i])
	{
		if (str[i] == c)
			prev = 1;
		else if (prev)
		{
			count++;
			if (str[i] != c)
				prev = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_counter(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			split[i++] = ft_substr(s - j, 0, j);
		}
		else
			s++;
	}
	split[i] = 0;
	return (split);
}
