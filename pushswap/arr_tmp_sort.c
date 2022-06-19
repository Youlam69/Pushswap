/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tmp_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:22:24 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 22:26:17 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fill_arr(t_ps *ps)
{
	t_list	*stack;
	int		i;

	ps->arr = (int *)malloc(sizeof(int) * ps->size);
	if (!ps->arr)
	{
		free_stack(&ps->stack_a, 1);
		exit(1);
	}
	stack = ps->stack_a;
	i = 0;
	while (stack && i < ps->size)
	{
		ps->arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
}

void	bubble_sort(t_ps *ps)
{
	int	i;
	int	*tmp;
	int	exec;

	tmp = ps->arr;
	exec = 1;
	while (exec)
	{
		exec = 0;
		i = 0;
		while ((i + 1) < ps->size)
		{
			if (tmp[i] > tmp[i + 1])
			{
				exec = 1;
				ft_swap(&tmp[i], &tmp[i + 1]);
			}
			i++;
		}
	}
}

void	sort_arr(t_ps *ps)
{
	fill_arr(ps);
	bubble_sort(ps);
}
