/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:58:38 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 21:52:44 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_list *stack)
{
	int		c;
	t_list	*tmp;

	tmp = stack;
	c = 0;
	while (tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}

t_list	*get_min(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (min->content > stack->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*get_max(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (max->content < stack->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	get_key(t_ps *ps)
{
	int	key;
	int	med;
	int	i;

	if (ps->size > 10 && ps->size <= 100)
		key = (ps->size - 1) / 5;
	else
		key = (ps->size - 1) / 12;
	i = 0;
	med = key;
	key++;
	ps->div = (ps->size - 1) / key;
	while (i < ps->div)
	{
		ps->key[i] = ps->arr[med];
		med = med + key;
		i++;
	}
}
