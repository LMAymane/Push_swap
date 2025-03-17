/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:01:06 by aylamiri          #+#    #+#             */
/*   Updated: 2024/11/22 15:42:32 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	str = NULL;
	return (NULL);
}

static int	count_word(char const *str, char separator)
{
	int	count;
	int	boolean;

	count = 0;
	while (*str)
	{
		boolean = 0;
		while (*str && *str == separator)
			str++;
		while (*str && *str != separator)
		{
			if (boolean == 0)
			{
				count++;
				boolean = 1;
			}
			str++;
		}
	}
	return (count);
}

static int	count_char(char const *str, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[j] != sep)
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		nbword;
	int		nbchar;
	int		i;
	char	**ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	nbword = count_word(s, c);
	ptr = malloc((nbword + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (i < nbword)
	{
		while (*s == c)
			s++;
		nbchar = count_char(s, c);
		ptr[i] = ft_substr(s, 0, nbchar);
		if (ptr[i] == NULL)
			return (ft_free(ptr));
		s += nbchar;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
