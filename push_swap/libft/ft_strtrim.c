/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:27:00 by aylamiri          #+#    #+#             */
/*   Updated: 2025/01/25 16:33:59 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_set(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (s1[i])
	{
		j = 0;
		c = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				c++;
			j++;
		}
		if (c == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	last_set(char const *s1, char const *set)
{
	int	i;
	int	c;
	int	len;

	len = ft_strlen(s1);
	while (len--)
	{
		i = 0;
		c = 0;
		while (set[i])
		{
			if (set[i] == s1[len])
				c++;
			i++;
		}
		if (c == 0)
			return (len);
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		first;
	int		last;

	i = 0;
	if (!s1)
		return (NULL);
	if (set[0] == '\0')
		return (ft_strdup(s1));
	first = first_set(s1, set);
	last = last_set(s1, set);
	if (first > last)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * ((last - first + 1) + 1));
	if (ptr == NULL)
		return (NULL);
	while (first <= last)
	{
		ptr[i] = s1[first];
		first++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
