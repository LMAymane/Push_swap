/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:04:13 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 17:42:28 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	handle_case(const char *str, int start, int length)
{
	int	i;

	i = 0;
	while (*(str + start) == '0')
	{
		length--;
		start++;
	}
	if (length < 19)
		return (0);
	if (length > 19 || ft_memcmp(str + start, "9223372036854775807", 19) > 0)
		return (1);
	return (0);
}

long	ft_atol(const char *str, t_list **stack, char **strs)
{
	long	num;
	int		counter;
	int		signe;
	int		start;

	counter = 0;
	num = 0;
	signe = 1;
	while ((str[counter] <= 13 && str[counter] >= 9) || str[counter] == ' ')
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter++] == '-')
			signe *= -1;
	}
	start = counter;
	while (ft_isdigit(str[counter]))
		num = num * 10 + (str[counter++] - '0');
	if (handle_case(str, start, counter - start))
		ft_error(stack, strs);
	return (signe * num);
}
