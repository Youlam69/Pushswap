/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:23:00 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 15:39:50 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*last_stack(t_list *node, int r)
{
	while (node->next)
	{
		if ((r) && (!node->next->next))
			return (node);
		node = node->next;
	}
	return (node);
}

void	init_stack_id(t_ps *ps)
{
	int		id;
	t_list	*tmp;

	id = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		tmp->id = ++id;
		tmp = tmp->next;
	}
	id = 0;
	tmp = ps->stack_b;
	while (tmp)
	{
		tmp->id = ++id;
		tmp = tmp->next;
	}
}
