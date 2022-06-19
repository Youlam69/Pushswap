/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:12:23 by abbelhac          #+#    #+#             */
/*   Updated: 2022/06/19 19:09:34 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	handler(t_ps *ps, char *op)
{
	if ((!ft_strcmp(op, "sa")) || !(ft_strcmp(op, "sb"))
		|| !(ft_strcmp(op, "ss")))
		stack_swap(ps, op, 0);
	else if ((!ft_strcmp(op, "pa")) || (!ft_strcmp(op, "pb")))
		push(ps, op, 0);
	else if ((!ft_strcmp(op, "ra")) || !(ft_strcmp(op, "rb"))
		|| (!ft_strcmp(op, "rr")))
		stack_rotate(ps, op, 0);
	else if ((!ft_strcmp(op, "rra")) || (!ft_strcmp(op, "rrb"))
		|| !ft_strcmp(op, "rrr"))
		stack_rotate(ps, op, 0);
	else
	{
		free_stack(&ps->stack_a, 1);
		if (op)
			free(op);
		exit(1);
	}
}

void	push_read(t_ps *ps)
{
	char	*line;
	char	*lin;

	ps->arr = NULL;
	line = NULL;
	line = get_next_line(0);
	lin = ft_strtrim(line, "\n");
	free(line);
	while (lin)
	{
		handler(ps, lin);
		free(lin);
		line = get_next_line(0);
		if (line)
		{
			lin = ft_strtrim(line, "\n");
			free(line);
		}
	}
	if (lin)
		free(lin);
}

int	main(int ac, char **av)
{
	t_ps	data;
	int		sorted;

	if (ac == 1)
		return (0);
	data = (t_ps){0};
	if (splity(av, &data))
		return (1);
	sorted = check_sort_dup(data.stack_a);
	if (sorted == 1 || sorted == 3)
	{
		free_stack(&data.stack_a, sorted);
		return (1);
	}
	push_read(&data);
	if (is_sorted(data.stack_a))
		ft_putstr_fd("\033[1;32mOK\033[0m\n", 1);
	else
		ft_putstr_fd("\033[1;31mKO\033[0m\n", 1);
	free_stack(&data.stack_a, 0);
}
