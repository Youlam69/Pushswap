/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:09:13 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/18 15:40:02 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
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
	int			counter;
	int			div;
	int			*arr;
	int			key[12];
	t_list		*stack_a;
	t_list		*stack_b;
}				t_ps;

// void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_swap(int *a, int *b);
int		check_sort_dup(t_list *stack);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stack(t_list **stack);
int		splity(char **av, t_list **stack);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str, int *error);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

t_list	*last_stack(t_list *node, int r);
void	init_stack_id(t_ps *ps);
void	push_min_to_b(t_ps *ps);
void	stack_swap(t_ps *ps, char *s, int bool);
void	push(t_ps *ps, char *s, int bool);
void	rotate(t_list **stack, int r);

// int		ft_printf(const char *str, ...);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
// char	*ft_calloc(size_t count, size_t size);
// char	*ft_strdup(const char *s1);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strtrim(char const *s1, char const *set);
// void	tofork(t_cp *cmd, char **env, int i, int fd2);
// size_t	ft_strlengt(const char *str);
// char	*ft_callocgt(size_t count, size_t size);
// char	*ft_strcatgt(char *dst, char *src);
// char	*ft_strjoingt(char *s1, char *s2);
// char	*ft_substrgt(char const *s, unsigned int start, size_t len);
// char	*get_next_line(int fd);
// int		ft_strcmp(const char *s1, const char *s2);

#endif