/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:41:51 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/19 19:09:38 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	free_stack(t_list **stack, int index)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
	if (index)
		ft_putstr_fd("Error\n", 2);
}

int	checkalpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			if ((str[i][j] < '0' || str[i][j] > '9'))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sort_dup(t_list *stack)
{
	t_list	*tmp;
	int		ref_2;
	int		ref;

	ref = 2;
	ref_2 = 0;
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content == tmp->content)
				ref_2 = 1;
			if (stack->content > tmp->content)
				ref = 0 ;
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (ref + ref_2);
}

int	fill_stack(t_list **stack, char **str)
{
	int		error;
	int		value;
	int		j;

	j = 0;
	while (str[j])
	{
		value = ft_atoi(str[j], &error);
		if (!error)
			ft_lstadd_back(stack, ft_lstnew(value));
		else
		{
			free_stack(stack, 1);
			free_splited(&str);
			return (1);
		}
		j++;
	}
	return (0);
}

int	splity(char **av, t_ps *ps)
{
	int		i;

	i = 1;
	while (av[i])
	{
		ps->str = ft_split(av[i], ' ');
		if (!ps->str)
		{
			free_stack(&ps->stack_a, 1);
			return (1);
		}
		if (checkalpha(ps->str))
		{
			free_stack(&ps->stack_a, 1);
			free_splited(&ps->str);
			return (1);
		}
		else if (fill_stack(&ps->stack_a, ps->str))
			return (1);
		if (ps->str)
			free_splited(&ps->str);
		i++;
	}
	return (0);
}
