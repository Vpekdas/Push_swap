# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2023/11/24 15:44:25 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =  instructions.c

LIBFT_PATH = Libft

FT_PRINTF_PATH = ft_printf

OBJECTS = $(SOURCES:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -Iinclude

RM = rm -f

.PHONY: all clean fclean re libft ft_printf

all: libft ft_printf $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -Llibft -lft -Lft_printf -lftprintf

libft: 
	$(MAKE) -C $(LIBFT_PATH)

ft_printf: 
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJECTS)
	$(MAKE) $(LIBFT_PATH) clean
	$(MAKE) $(FT_PRINTF_PATH_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBFT_PATH) fclean
	$(MAKE) $(FT_PRINTF_PATH) fclean

re: fclean all