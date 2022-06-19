/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:10:41 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 22:42:35 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	case_of_3(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->stack_a->content;
	second = ps->stack_a->next->content;
	if (ps->stack_a->next->next)
		third = ps->stack_a->next->next->content;
	if ((ps->size == 2 && first > second) || (first > second && first < third))
		stack_swap(ps, "sa", 1);
	else if (second < third && first > third)
		stack_rotate(ps, "ra", 1);
	else if (first < second && first > third)
		stack_rotate(ps, "rra", 1);
	else if ((first > second) && (second > third))
	{
		stack_swap(ps, "sa", 1);
		stack_rotate(ps, "rra", 1);
	}
	else if (first < third && second > third)
	{
		stack_swap(ps, "sa", 1);
		stack_rotate(ps, "ra", 1);
	}
}

void	case_of_10(t_ps *ps)
{
	while (!is_sorted(ps->stack_a) || (is_sorted(ps->stack_a) && ps->stack_b))
	{
		if ((stack_size(ps->stack_a)) <= 3)
			case_of_3(ps);
		else
		{
			ps->min = get_min(ps->stack_a);
			ps->med = (stack_size(ps->stack_a) / 2);
			while (ps->stack_a->content != ps->min->content)
			{
				if (ps->med >= ps->min->id)
					stack_rotate(ps, "ra", 1);
				else
					stack_rotate(ps, "rra", 1);
				ps->min = get_min(ps->stack_a);
			}
			if (!(is_sorted(ps->stack_a))
				&& ps->stack_a->content == ps->min->content)
				push(ps, "pb", 1);
		}
		while (is_sorted(ps->stack_a) && ps->stack_b)
			push(ps, "pa", 1);
	}
}

t_list	*get_under_key(t_list *stack, int i)
{
	while (stack)
	{
		if (stack->content <= i)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	case_of_100(t_ps *ps)
{
	t_list	*min;
	t_list	*max;

	sort_arr(ps);
	get_key(ps);
	push_min_to_b(ps);
	while (ps->stack_a)
	{
		min = get_min(ps->stack_a);
		push_to_b(ps, min);
	}
	while (ps->stack_b)
	{
		max = get_max(ps->stack_b);
		push_to_a(ps, max);
		if (!ps->stack_b)
			break ;
	}
}

void	stack_sort(t_ps *ps)
{
	if (ps->size <= 10)
		case_of_10(ps);
	else if (ps->size > 10)
		case_of_100(ps);
	if (ps->arr)
		free (ps->arr);
}
