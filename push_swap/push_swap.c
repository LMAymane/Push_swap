/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:17:01 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:00 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack, int ac, char **av)
{
	char	**str;
	int		i;
	long	nb;

	str = NULL;
	i = 0;
	if (ac < 1)
		return ;
	while (*(++av))
	{
		str = ft_split(*av, ' ');
		if (!*str)
			ft_error(stack, str);
		while (str[i])
		{
			if (!ft_check_valid(str[i]))
				ft_error(stack, str);
			nb = ft_atol(str[i++], stack, str);
			if (nb > INT_MAX || nb < INT_MIN)
				ft_error(stack, str);
			ft_lstadd_back(stack, ft_lstnew(nb));
		}
		ft_free_str(str);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		init_stack(&stack_a, ac, av);
		if (!stack_a || ft_check_rep(stack_a))
			ft_error(&stack_a, NULL);
		sort(&stack_a, &stack_b);
		ft_free(&stack_a);
	}
}
