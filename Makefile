# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:29:10 by asuteau           #+#    #+#              #
#    Updated: 2024/02/28 09:07:33 by asuteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- VARIABLES --------------------------------- #

NAME		= 	push_swap

BONUS_NAME	=	checker

SRC_DIR		= 	./src

BONUS_SRC_DIR	=	./bonus

SRC			= 	push_swap.c \
				push_swap_00_tools.c \
				push_swap_00_errors_and_free.c \
				push_swap_01_check_args.c \
				push_swap_02_ft_split.c \
				push_swap_03_fillup.c \
				push_swap_04_check_doubles_and_if_sorted.c \
				push_swap_05a_swap.c \
				push_swap_05b_push.c \
				push_swap_05c_rotate.c \
				push_swap_05c_reverse_rotate.c \
				push_swap_06_calculate_median.c \
				push_swap_07a_algo_and_sort_two_three.c \
				push_swap_07b_sort_four.c \
				push_swap_07c_sort_five_six_seven.c \
				push_swap_07d_sort_eight.c \
				push_swap_07e_sort_big_number.c \

BONUS_SRC		= 	checker/checker.c \
					checker/checker_01_read_actions.c \
					checker/checker_02_ft_split.c \
					checker/checker_03_execute_actions.c \
					checker/checker_04_exec_utils.c \
					push_swap/push_swap_00_tools.c \
					push_swap/push_swap_00_errors_and_free.c \
					push_swap/push_swap_01_check_args.c \
					push_swap/push_swap_02_ft_split.c \
					push_swap/push_swap_03_fillup.c \
					push_swap/push_swap_04_check_doubles_and_if_sorted.c \
					push_swap/push_swap_05a_swap.c \
					push_swap/push_swap_05b_push.c \
					push_swap/push_swap_05c_rotate.c \
					push_swap/push_swap_05c_reverse_rotate.c

SRCS		= 	$(addprefix $(SRC_DIR)/, $(SRC))

BONUS_SRCS			=	$(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC))

INCL_DIR	=	inc

OBJECTS		= 	$(SRCS:.c=.o)

BONUS_OBJECTS	=	$(BONUS_SRCS:.c=.o)

CC			= 	cc

CFLAGS		= 	-Wall -Wextra -Werror

# ---------------------------------- RULES ----------------------------------- #

.c.o:	
			$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJECTS)
			$(CC) $(CFLAGS) -I $(INCL_DIR) -o $(NAME) $(OBJECTS)

$(BONUS_NAME) : $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) -I $(INCL_DIR) -o $(BONUS_NAME) $(BONUS_OBJECTS)

all: 		$(NAME)

bonus: $(BONUS_NAME)

clean:
			rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: 	clean
			rm -f $(NAME) $(BONUS_NAME)

re : 		fclean $(NAME)

.PHONY: 	all clean fclean re
