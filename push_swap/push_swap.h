/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:17:38 by aylamiri          #+#    #+#             */
/*   Updated: 2025/02/03 16:49:17 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int					value;
	int					index;
	int					current_pos;
	int					cost_move;
	int					cheapest;
	int					above_median;
	struct s_list		*next;
	struct s_list		*prev;
	struct s_list		*target_node;
}	t_list;
void		ft_error(t_list	**stack, char	**str);
void		ft_free_str(char	**str);
void		ft_free(t_list	**stack);
int			ft_check_valid(const char	*str);
int			ft_check_rep(t_list *stack);
int			ft_check_sorted(t_list **stack);
long		ft_atol(const char *str, t_list **stack, char **strs);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new_node);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		sort(t_list **stack_a, t_list **stack_b);
int			sa(t_list *stack_a, int print);
int			sb(t_list *stack_b, int print);
int			ss(t_list *stack_a, t_list *stack_b, int print);
int			ra(t_list **stack_a, int print);
int			rb(t_list **stack_b, int print);
int			rr(t_list **stack_a, t_list **stack_b, int print);
int			rra(t_list **stack_a, int print);
int			rrb(t_list **stack_b, int print);
int			rrr(t_list **stack_a, t_list **stack_b, int print);
int			pa(t_list **stack_a, t_list **stack_b, int print);
int			pb(t_list **stack_b, t_list **stack_a, int print);
void		sort_three(t_list **stack);
void		init_position(t_list *stack);
void		set_target(t_list *stack_a, t_list *stack_b);
void		calculate_cost(t_list *stack_a, t_list *stack_b);
void		find_cheapest(t_list *stack);
void		last_move(t_list **stack_a);
void		rotate_both(t_list **stack_a,
				t_list **stack_b,
				t_list *cheapest_node);
void		reverse_rotate_both(t_list **stack_a,
				t_list **stack_b,
				t_list *cheapest_node);
void		finish_rotation(t_list **stack, t_list *top_node, char stack_name);
t_list		*get_min(t_list *stack);
t_list		*get_cheapest(t_list *stack);
#endif
