/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:54:54 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/19 19:54:23 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

// void	push_min_to_b(t_ps *ps)
// {
// 	t_list	*smaller;
// 	int		i;

// 	i = 0;
// 	while (i < ps->div)
// 	{
// 		while (1)
// 		{
// 			smaller = get_under_key(ps->stack_a, ps->key[i]);
// 			if (!smaller)
// 				break ;
// 			else
// 				push_to_b(ps, smaller);
// 		}
// 		i++;
// 	}
// }

void	stack_swap(t_ps *ps, char *s, int bool)
{
	if (!ft_strcmp(s, "sa") && ps->stack_a && ps->stack_a->next)
		ft_swap(&ps->stack_a->content, &ps->stack_a->next->content);
	else if (!ft_strcmp(s, "sb") && ps->stack_b && ps->stack_b->next)
		ft_swap(&ps->stack_b->content, &ps->stack_b->next->content);
	else if (!ft_strcmp(s, "ss") && ps->stack_a && ps->stack_b
		&& ps->stack_a->next && ps->stack_b->next)
	{
		ft_swap(&ps->stack_a->content, &ps->stack_a->next->content);
		ft_swap(&ps->stack_b->content, &ps->stack_b->next->content);
	}
	if (bool)
	{
		ft_putstr_fd(s, 1);
		write(1, "\n", 1);
	}
}

void	push(t_ps *ps, char *s, int bool)
{
	t_list		*tmp;

	if (!ft_strcmp(s, "pb") && ps->stack_a)
	{
		tmp = ps->stack_b;
		ps->stack_b = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		ps->stack_b->next = tmp;
	}
	else if (!ft_strcmp(s, "pa") && ps->stack_b)
	{
		tmp = ps->stack_a;
		ps->stack_a = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		ps->stack_a->next = tmp;
	}
	if (bool)
	{
		ft_putstr_fd(s, 1);
		write(1, "\n", 1);
	}
	init_stack_id(ps);
}

void	rotate(t_list **stack, int rev)
{
	t_list	*tmp;
	t_list	*lst;

	if ((!rev) && (*stack) && (*stack)->next)
	{
		tmp = (*stack);
		lst = last_stack((*stack), rev);
		(*stack) = tmp->next;
		lst->next = tmp;
		tmp->next = NULL;
	}
	else if ((rev) && (*stack) && (*stack)->next)
	{
		tmp = last_stack((*stack), 0);
		lst = last_stack((*stack), rev);
		lst->next = NULL;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void	stack_rotate(t_ps *ps, char *s, int bool)
{
	if (!ft_strcmp(s, "ra"))
		rotate(&ps->stack_a, 0);
	else if (!ft_strcmp(s, "rb"))
		rotate(&ps->stack_b, 0);
	else if (!ft_strcmp(s, "rr"))
	{
		rotate(&ps->stack_a, 0);
		rotate(&ps->stack_b, 0);
	}
	else if (!ft_strcmp(s, "rra"))
		rotate(&ps->stack_a, 1);
	else if (!ft_strcmp(s, "rrb"))
		rotate(&ps->stack_b, 1);
	else if (!ft_strcmp(s, "rrr"))
	{
		rotate(&ps->stack_a, 1);
		rotate(&ps->stack_b, 1);
	}
	if (bool)
	{
		ft_putstr_fd(s, 1);
		write(1, "\n", 1);
	}
	init_stack_id(ps);
}
