/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:29:58 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 16:08:43 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_ps	data;
	t_list	*tmp;

	if (splity(av, &(data.stack_a)))
		return (1);
	if (check_sort_dup(data.stack_a))
	{
		printf("stack kharj azabi\n");
		free_stack(&(data.stack_a));
		return (0);
	}
	tmp = data.stack_a;
	printf("before swap\n");
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	stack_swap(&data, "sa", 1);
	tmp = data.stack_a;
	printf("\nbefore swap\n");
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	push(&data, "pb", 1);
	push(&data, "pb", 1);
	push(&data, "pb", 1);
	push(&data, "pb", 1);
	printf("\nafter push to stack b\n");
	tmp = data.stack_b;
	printf("\nbefore push\n");
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}


	tmp = data.stack_b;
	printf("after  b swap\n");
	stack_swap(&data, "sb", 1);
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	return (0);
}


