/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:33:29 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 20:26:47 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*bottom;

	if (!stack || ft_lstsize(*stack) < 2)
		return (0);
	head = *stack;
	bottom = ft_lstlast(*stack);
	*stack = head->next;
	(*stack)->prev = NULL;
	head->prev = bottom;
	head->next = NULL;
	bottom->next = head;
	return (1);
}

int	ra(t_list **stack_a, int print)
{
	if (!ft_rotate(stack_a))
		return (0);
	if (print)
		ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_list **stack_b, int print)
{
	if (!ft_rotate(stack_b))
		return (0);
	if (print)
		ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b, int print)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (print)
		ft_putendl_fd("rr", 1);
	return (0);
}
