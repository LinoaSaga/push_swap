# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:37:05 by ljudd             #+#    #+#              #
#    Updated: 2025/05/14 09:31:45 by ljudd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap
SOURCES			= push_swap.c \
	ft_pushswap_inputs.c \
	ft_pushswap_move1.c \
	ft_pushswap_move2.c \
	ft_pushswap_move3.c
HEADER			= push_swap.h
INCLUDES		= push_swap.h -Iprintf
OBJECTS			= $(SOURCES:.c=.o)

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
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus $(LIBFT)