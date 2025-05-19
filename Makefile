# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:37:05 by ljudd             #+#    #+#              #
#    Updated: 2025/05/19 16:33:41 by ljudd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap
NAME_BONUS		= checker
SOURCES			= src/push_swap.c \
	src/ft_pushswap_inputs.c \
	src/ft_pushswap_move1.c \
	src/ft_pushswap_move2.c \
	src/ft_pushswap_move3.c \
	src/ft_pushswap_algo.c \
	src/ft_pushswap_algo_utils.c \
	src/ft_pushswap_algoturk.c \
	src/ft_pushswap_algoturk_p2.c \
	src/ft_pushswap_algoturk_p4.c \
	src/ft_pushswap_algon5.c
SOURCES_BONUS	= src/checker_bonus.c \
	src/ft_pushswap_inputs.c \
	src/ft_pushswap_move1.c \
	src/ft_pushswap_move2.c \
	src/ft_pushswap_move3.c \
	src/ft_pushswap_algo_utils.c	
SOURCES_GNL = gnl/get_next_line_bonus.c \
	gnl/get_next_line_utils_bonus.c
HEADER			= includes/push_swap.h
INCLUDES		= includes -Iprintf -Ignl
OBJECTS			= $(SOURCES:.c=.o)
OBJECTS_BONUS	= $(SOURCES_BONUS:.c=.o)
OBJECTS_GNL		= $(SOURCES_GNL:.c=.o)

LIBFT			= libftprintf.a
LIBFT_FLAGS		= -Lprintf -lftprintf
LIBFT_DIR		= ./printf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all --no-print-directory
	make -C $(LIBFT_DIR) bonus --no-print-directory

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_GNL)
	make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: $(LIBFT) $(OBJECTS_BONUS) $(OBJECTS_GNL)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(OBJECTS_GNL) $(LIBFT_FLAGS) -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus $(LIBFT)