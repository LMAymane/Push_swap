/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:47:36 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 20:18:28 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_position(t_list *stack)
{
	int	i;
	int	len;

	i = 0;
	if (!stack)
		return ;
	len = ft_lstsize(stack);
	while (i < len)
	{
		stack->current_pos = i;
		if (i++ <= len / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}

void	set_target(t_list *stack_a, t_list *stack_b)
{
	int		signe;
	t_list	*head_a;

	if (!stack_a || !stack_b)
		return ;
	while (stack_b)
	{
		signe = 0;
		head_a = stack_a;
		while (head_a)
		{
			if (head_a->value > stack_b->value)
			{
				if (!signe || stack_b->target_node->value > head_a->value)
				{
					stack_b->target_node = head_a;
					signe = 1;
				}
			}
			head_a = head_a->next;
		}
		if (!signe)
			stack_b->target_node = get_min(stack_a);
		stack_b = stack_b->next;
	}
}

void	calculate_cost(t_list *stack_a, t_list *stack_b)
{
	int	cost;
	int	len_a;
	int	len_b;

	if (!stack_a || !stack_b)
		return ;
	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		cost = 0;
		if (stack_b->above_median)
			cost += stack_b->current_pos;
		else
			cost += (len_b - stack_b->current_pos);
		if (stack_b->target_node->above_median)
			cost += stack_b->target_node->current_pos;
		else
			cost += (len_a - stack_b->target_node->current_pos);
		stack_b->cost_move = cost;
		stack_b = stack_b->next;
	}
}

void	find_cheapest(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	tmp->cheapest = 1;
	stack = stack->next;
	while (stack)
	{
		if (tmp->cost_move > stack->cost_move)
		{
			tmp->cheapest = 0;
			stack->cheapest = 1;
			tmp = stack;
		}
		stack = stack->next;
	}
}
