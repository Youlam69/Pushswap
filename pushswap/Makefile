# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:24:45 by ylamraou          #+#    #+#              #
#    Updated: 2022/06/19 19:52:29 by ylamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAG = -Wall -Wextra -Werror
AR = ar rcs
CC = cc
# #########SRCS#############
SRC = ft_split.c \
lib_ft.c \
libft.c \
ft_atoi.c \
list.c \
check_arg.c \
instructions.c \
instructions_utils.c \
utils.c \
sorting.c  \
sorting_utils.c \
arr_tmp_sort.c \
pushswap.c \
get_next_line_utils.c \
get_next_line.c

# #########SRCS_BONUS#############
SRC_BONUS = ./bonus/check_arg_bonus.c \
./bonus/ft_atoi_bonus.c \
./bonus/get_next_line_bonus.c \
./bonus/instructions_bonus.c \
./bonus/lib_ft_bonus.c \
./bonus/list_bonus.c \
./bonus/utils_bonus.c \
./bonus/checker_bonus.c \
./bonus/ft_split_bonus.c \
./bonus/get_next_line_utils_bonus.c \
./bonus/instructions_utils_bonus.c \
./bonus/libft_bonus.c

# ######### HEADERS #############

HEADER_BONUS = ./bonus/pushswap_bonus.h
HEADER = pushswap.h
############## OBJS #############

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

# ########### EXECS ###############

NAME = push_swap
CHECKER = checker


all: $(NAME)

bonus:  all $(CHECKER)

$(CHECKER) : $(OBJS_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAG) $(OBJS_BONUS) -o $(CHECKER)

$(NAME): $(OBJS) $(HEADER)
		@$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c 
	$(CC) $(CFLAG) -c $<

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: fclean clean all bonus re