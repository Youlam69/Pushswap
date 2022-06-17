/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:29:58 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/17 23:54:45 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int ac, char **av)
{
	t_ps data;

	splity(av, &(data.stack_a));
	if (check_sort_dup(data.stack_a))
	{
		printf("stack kharj azabi\n");
		free_stack(&(data.stack_a));
		return 0;
	}
	while(data.stack_a)
	{
		printf("%d\n", data.stack_a->content);
		data.stack_a = data.stack_a->next;
	}
	return 0;
}