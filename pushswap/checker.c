/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:41:51 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/17 21:58:05 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void free_stack(t_list **stack)
{
	t_list *tmp;

	while(*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

int checkalpha(char **str)
{
	int i = 1;
	int j = 0;
	
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if((str[i][j] < '0' || str[i][j] > '9') && str[i][0] != '-' && str[i][0] != '+')
				return -1;
			j++;
		}
		i++;
	}
	return 0;
}

int	check_sort_dup(t_list *stack)
{
	t_list *tmp;
	int		ref_2 = 0;
	int		ref = 1;
	while(stack)
	{
		tmp = stack->next;
		while(tmp)
		{
			if(stack->content == tmp->content)
				ref_2 = 1;
			if(stack->content > tmp->content)
				ref = 0 ;
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (ref + ref_2);
}

int	splity(char **av, t_list **stack)
{
	int		i;
	int		j;
	int		error;
	int		value;
	char	**str;

	i = 1;
	str = NULL;
	while(av[i])
	{
		j= 0;
		str = ft_split(av[i], ' ');
		if(!str)
		{
			free_stack(stack);
			return 1;
		}
		if (checkalpha(str))
		{
			free_stack(stack);
			return 1;
		}
		else
		{
			while(str[j])
			{
				value = ft_atoi(str[j], &error);
				if(!error)
					ft_lstadd_back(stack, ft_lstnew(value));
				else
				{
					free_stack(stack);
					return 1;
				}
				j++;
			}
		}
		i++;
	}
	return 0;
}
int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	splity(av, &stack_a);
	if (check_sort_dup(stack_a))
	{
		printf("stack kharj azabi\n");
		free_stack(&stack_a);
		return 0;
	}
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return 0;
}