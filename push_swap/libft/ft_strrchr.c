/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:07 by aylamiri          #+#    #+#             */
/*   Updated: 2024/11/15 22:21:18 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*j;

	j = NULL;
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			j = (char *)s;
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s);
	return (j);
}
