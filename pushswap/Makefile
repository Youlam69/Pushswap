# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:24:45 by ylamraou          #+#    #+#              #
#    Updated: 2022/06/19 02:07:00 by ylamraou         ###   ########.fr        #
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
instructions.c \
instructions_utils.c \
utils.c \
sorting.c  \
sorting_utils.c \
arr_tmp_sort.c \
pushswap.c
# sorting.c 

HEADER = pushswap.h

OBJS = $(SRC:.c=.o)
# #########library#############
NAME = pushswap.a
# ###########EXEC###############
EXEC = push_swap

all: $(EXEC)
# all: $(NAME)

$(EXEC) : $(NAME)
	@$(CC) $(CFLAG) pushswap.c $(NAME) -o push_swap

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS) 

%.o : %.c $(HEADER)
	$(CC) $(CFLAG) -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: fclean clean all re