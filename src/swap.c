/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:41:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/02 14:51:56 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	swap_ll(t_llist *llist)
{
	t_llist	tmp;

	if (!llist || !llist->next)
		return ;
	if (llist_size(llist) < 2)
		return ;
	tmp.data = llist->data;
	llist->data = llist->next->data;
	llist->next->data = tmp.data;
}

void	swap_tl(t_list *stack)
{
	t_list	tmp;

	if (!stack || !stack->next)
		return ;
	tmp.content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp.content;
}

char	*swap_a(t_list *stack)
{
	swap_tl(stack);
	return (ft_strdup(SA));
}

char	*swap_b(t_list *stack)
{
	swap_tl(stack);
	return (ft_strdup(SB));
}

char	*swap_all(t_llist *llist)
{
	swap_ll(llist);
	return (ft_strdup(SA));
}

char	*swap_bll(t_llist *llist)
{
	swap_ll(llist);
	return (ft_strdup(SB));
}