/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/05 14:07:29 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"
#include "../ft_pow/ft_pow.h"

t_list	*llst_tolst(t_llist *llst)
{
	t_list	*lst;

	while (llst)
	{
		ft_lstadd_back(&lst, ft_lstnew(make_data(*(int *)(llst->data))));
		llst = llst->next;
	}
	return (lst);
}

t_llist	*lst_tollst(t_list *lst)
{
	t_llist	*llst;

	while (lst)
	{
		add_back(&llst, newnode(make_data(*(int *)(lst->content))));
		lst = lst->next;
	}
	return (llst);
}

char	*trivial_sort(t_llist **llst)
{
	t_list		*lst;
	t_list		*b;
	char		*oper;

	lst = llst_tolst(*llst);
	b = NULL;
	oper = sort_b(&lst, &b, 3);
	ft_lstclear(&b, &del_node);
	llist_clear(llst, &del_node);
	*llst = lst_tollst(lst);
	ft_lstclear(&lst, &del_node);
	return (oper);
}

char	*push_swap(t_llist **a)
{
	char	*oper;

	if (!a || !(*a))
		return (NULL);
	if (llist_size(*a) < 10)
		return (trivial_sort(a));
	oper = sndtimes(a, round_num(scatter(llist_size(*a))));
	return (oper);
}