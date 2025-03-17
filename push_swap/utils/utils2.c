/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:16 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 19:33:36 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_list **stack_a,
								t_list **stack_b,
								t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rr(stack_a, stack_b, 1);
	init_position(*stack_a);
	init_position(*stack_b);
}

void	reverse_rotate_both(t_list **stack_a,
												t_list **stack_b,
												t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, 1);
	init_position(*stack_a);
	init_position(*stack_b);
}

void	finish_rotation(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
