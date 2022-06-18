# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:24:45 by ylamraou          #+#    #+#              #
#    Updated: 2022/06/18 15:26:00 by ylamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAG = -Wall -Wextra -Werror
AR = ar rcs
CC = cc
# #########SRCS#############
SRC = ft_split.c \
lib_ft.c \
ft_atoi.c \
list.c \
check_arg.c \
instructions_utils.c \
instructions.c

OBJS = $(SRC:.c=.o)
# #########library#############
NAME = pushswap.a
# ###########EXEC###############
# EXEC = push_swap

# all: $(EXEC)
all: $(NAME)

# $(EXEC) : $(NAME) 
# 	@$(CC) $(CFLAG) $(NAME) -g -o $(EXEC) 

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