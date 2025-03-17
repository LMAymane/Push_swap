/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:56:59 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 20:28:18 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*temp_stack;

	if (!*stack_from)
		return (0);
	temp_stack = (*stack_from)->next;
	ft_lstadd_front(stack_to, *stack_from);
	*stack_from = temp_stack;
	return (1);
}

int	pa(t_list **stack_a, t_list **stack_b, int print)
{
	if (!push(stack_a, stack_b))
		return (0);
	if (print)
		ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_list **stack_b, t_list **stack_a, int print)
{
	if (!push(stack_b, stack_a))
		return (0);
	if (print)
		ft_putendl_fd("pb", 1);
	return (1);
}
