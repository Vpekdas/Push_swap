# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2024/01/04 16:51:23 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =  apply_push_to_a.c \
			apply_push_to_b.c \
			case_push_to_a.c \
			case_push_to_b.c \
			checking_functions.c \
			checking_functions_split.c \
			create_list_argv.c \
			instruction_push.c \
			instruction_reverse_rotate.c \
			instruction_rotate.c \
			instruction_swap.c \
			main.c \
			sorting_algo.c \
			utils_functions.c \
			utils_functions2.c \
			
LIBFT_PATH = Libft

FT_PRINTF_PATH = ft_printf

OBJECTS = $(SOURCES:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -g3 -Iinclude

RM = rm -f

.PHONY: all clean fclean re libft ft_printf

all: libft ft_printf $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -LLibft -lft -Lft_printf -lftprintf

libft: 
	$(MAKE) -C $(LIBFT_PATH)

ft_printf: 
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJECTS)
	cd $(LIBFT_PATH) && make clean
	cd $(FT_PRINTF_PATH) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBFT_PATH) && make fclean
	cd $(FT_PRINTF_PATH) && make fclean

re: fclean all