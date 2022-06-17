# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:24:45 by ylamraou          #+#    #+#              #
#    Updated: 2022/06/17 23:35:14 by ylamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAG = -Wall -Wextra -Werror
AR = ar rcs
CC = cc
# #########SRCS#############
SRC = ft_split.c \
ft_atoi.c \
list.c \
check_arg.c \
ft_putstr.c
# lib_ft.c \
libft.c \

OBJS = $(SRC:.c=.o)
# #########library#############
NAME = pushswap.a
# ###########EXEC###############
# EXEC = pushswap

# all: $(EXEC)
all: $(NAME)

# $(EXEC) : $(NAME) 
# 	@$(CC) $(CFLAG) $(NAME) -g -o pipex 

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS) 

%.o : %.c
	$(CC) $(CFLAG) -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: fclean clean all re