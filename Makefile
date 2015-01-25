# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:29:52 by jponcele          #+#    #+#              #
#    Updated: 2014/04/27 15:35:15 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = ft_malloc.c\
	  malloc_test_max_tiny.c
	  # malloc_test2.c

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

LFT = ./libft/libft.a

CC = clang
CFLAGS = -Wall -Werror -Wextra -g

HEAD = -I ./includes -I ./libft/includes/

all: $(NAME)

$(NAME): ft_malloc

ft_malloc: $(DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(MAKE) -C ./libft/
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT) $(LPRINTF)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(RFLAGS) ft_malloc
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re