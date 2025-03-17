/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:56:51 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 20:25:51 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (!stack || ft_lstsize(*stack) < 2)
		return (-1);
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	return (1);
}

int	rra(t_list **stack_a, int print)
{
	if (!reverse_rotate(stack_a))
		return (0);
	if (print)
		ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_list **stack_b, int print)
{
	if (!reverse_rotate(stack_b))
		return (0);
	if (print)
		ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (0);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_putendl_fd("rrr", 1);
	return (1);
}
