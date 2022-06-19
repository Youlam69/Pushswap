/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:29:58 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/19 02:08:06 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	if (sorted)
	{
		free_stack(&(data.stack_a), sorted - 2);
		if (sorted == 2)
			exit(0);
		return (1);
	}
	data.size = stack_size(data.stack_a);
	stack_sort(&data);
	free_stack(&(data.stack_a), 0);
	// while(1){}
	return (0);
}
