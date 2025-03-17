/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:22:22 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 20:28:57 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(t_list *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!stack || !stack->next)
		return (0);
	tmp_value = stack->value;
	tmp_index = stack->index;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->next->value = tmp_value;
	stack->next->index = tmp_index;
	return (1);
}

int	sa(t_list *stack_a, int print)
{
	if (!ft_swap(stack_a))
		return (0);
	if (print)
		ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_list *stack_b, int print)
{
	if (!ft_swap(stack_b))
		return (0);
	if (print)
		ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_list *stack_a, t_list *stack_b, int print)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return (0);
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (print)
		ft_putendl_fd("ss", 1);
	return (1);
}
