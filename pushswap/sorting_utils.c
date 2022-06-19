/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:45:23 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 21:47:16 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_to_a(t_ps *ps, t_list *max)
{
	ps->med = stack_size(ps->stack_b) / 2;
	while (ps->stack_b->content != max->content)
	{
		if (ps->med >= max->id)
			stack_rotate(ps, "rb", 1);
		else
			stack_rotate(ps, "rrb", 1);
	}
	if (ps->stack_b->content == max->content)
		push(ps, "pa", 1);
}

void	push_to_b(t_ps *ps, t_list *smaller)
{
	ps->med = stack_size(ps->stack_a) / 2;
	while (ps->stack_a->content != smaller->content)
	{
		if (ps->med >= smaller->id)
			stack_rotate(ps, "ra", 1);
		else
			stack_rotate(ps, "rra", 1);
	}
	if (ps->stack_a->content == smaller->content)
		push(ps, "pb", 1);
}
