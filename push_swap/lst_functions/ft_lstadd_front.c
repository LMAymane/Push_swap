/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:31:42 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 17:43:25 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst != NULL)
	{
		new->next = (*lst);
		(*lst)->prev = new;
		new->prev = NULL;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
	}
	*lst = new;
}
