/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:44:52 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/17 15:06:35 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char **spliter(char **av)
{
	int	i;
	int	j;
	char	**str;
	char 	**stock;
	char	**stock2;
	i = 1;
	j = 0;
	while(av[i])
	{
		str = ft_split(av[i], ' ');
		j = 0;
		while(str[j])
		{
			
		}
			

	return (str);
}

int main(int ac, char **av)
{
	char **f;
	f = spliter(av);
	int i = 0;
	while(f[i])
	{
		printf("%s",f[i]);
		i++;
	}
	
}