/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:35:08 by aylamiri          #+#    #+#             */
/*   Updated: 2024/11/19 21:24:36 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				i;
	char			str[10];

	nb = n;
	i = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1;
	}
	while (nb)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(str[i], fd);
}
