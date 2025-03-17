/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:11:03 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/01 22:38:50 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	if (*lst != NULL)
	{
		node = ft_lstlast(*lst);
		node->next = new;
		new->prev = node;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
	}
}
