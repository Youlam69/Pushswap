/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:09:13 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/19 19:20:13 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>

typedef struct s_list
{
	int					content;
	int					id;
	struct s_list		*next;
}						t_list;

typedef struct s_ps
{
	int			size;
	int			div;
	int			*arr;
	int			key[12];
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*min;
	int			med;
	char		**str;
}				t_ps;

// void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_swap(int *a, int *b);
int		check_sort_dup(t_list *stack);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stack(t_list **stack, int index);
void	free_splited(char ***str);
int		splity(char **av, t_ps *ps);

size_t	ft_strlen(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str, int *error);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

char	*ft_substrgt(char const *s, unsigned int start, size_t len);
char	*ft_strjoingt(char *s1, char *s2);
char	*get_next_line(int fd);

t_list	*last_stack(t_list *node, int rev);
void	init_stack_id(t_ps *ps);
// void	push_min_to_b(t_ps *ps);
void	stack_swap(t_ps *ps, char *s, int bool);

void	push(t_ps *ps, char *s, int bool);
void	stack_rotate(t_ps *ps, char *s, int bool);
int		stack_size(t_list *stack);
// void	case_of_3(t_ps *ps);
// void	case_of_10(t_ps *ps);
// t_list	*get_under_key(t_list *stack, int i);
// void	case_of_100(t_ps *ps);

void	stack_sort(t_ps *ps);
void	push_to_a(t_ps *ps, t_list *max);
void	push_to_b(t_ps *ps, t_list *smaller);
int		is_sorted(t_list *stack);
// t_list	*get_max(t_list *stack);
// t_list	*get_min(t_list *stack);

#endif