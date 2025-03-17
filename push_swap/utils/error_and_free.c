/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:04:00 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 19:36:42 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	ft_free(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	*stack = NULL;
}

void	ft_error(t_list **stack, char **str)
{
	write(1, "Error\n", 6);
	ft_free(stack);
	ft_free_str(str);
	exit(0);
}
