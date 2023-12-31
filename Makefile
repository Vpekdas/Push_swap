# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2023/12/29 15:07:02 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =  instruction_push.c \
			instruction_swap.c \
			instruction_rotate.c \
			instruction_reverse_rotate.c \
			create_list_argv.c \
			main.c \
			checking_errors.c \
			sort_three.c \
			sort_five.c \
			radix_sort.c \
			sort_opti.c \
			opti_push_to_b.c \



LIBFT_PATH = Libft

FT_PRINTF_PATH = ft_printf

OBJECTS = $(SOURCES:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -Iinclude

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