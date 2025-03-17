/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:13:26 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 20:32:14 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_nodes(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, cheapest_node->target_node, 'a');
	pa(stack_a, stack_b, 1);
}

void	init_nodes(t_list **stack_a, t_list **stack_b)
{
	init_position(*stack_a);
	init_position(*stack_b);
	set_target(*stack_a, *stack_b);
	calculate_cost(*stack_a, *stack_b);
	find_cheapest(*stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(*stack_a, 1);
	}
	else if (ft_lstsize(*stack_a) == 3 && !ft_check_sorted(stack_a))
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(stack_a))
	{
		while (ft_lstsize(*stack_a) > 3)
			pb(stack_b, stack_a, 1);
		sort_three(stack_a);
		while (*stack_b)
		{
			init_nodes(stack_a, stack_b);
			move_nodes(stack_a, stack_b);
		}
		init_nodes(stack_a, stack_b);
		last_move(stack_a);
	}
}
