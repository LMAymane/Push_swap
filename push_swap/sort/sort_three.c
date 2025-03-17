/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:04:18 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 17:42:46 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_index(t_list *stack)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
		{
			i = j;
			max = stack->value;
		}
		j++;
		stack = stack->next;
	}
	return (i);
}

void	sort_three(t_list **stack)
{
	int	index_max;

	if (!stack || !*stack)
		return ;
	index_max = get_max_index(*stack);
	if (index_max == 0)
		ra(stack, 1);
	else if (index_max == 1)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack, 1);
}
