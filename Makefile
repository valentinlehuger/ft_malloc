# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:44:25 by vlehuger          #+#    #+#              #
#    Updated: 2014/04/20 17:13:06 by vlehuger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
		HOSTTYPE := $(shell uname -m)
endif

NAME= libft_malloc_$(HOSTTYPE).so
LS = libft_malloc.so

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = ft_malloc.c\
	  ft_free.c\
	  ft_realloc.c\
	  show_alloc_mem.c\

SRC += get_params.c\
	   get_malloc.c

SRC += ft_bzero.c\
	   ft_memcpy.c\
	   ft_memset.c\
	   ft_putaddress.c\
	   ft_putchar.c\
	   ft_putstr.c\
	   ft_putnbr.c\

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

CC = clang
CFLAGS = -Wall -Werror -Wextra -fpic

AR = ar
ARFLAGS = -rc

HEAD = -I ./includes/

all: $(NAME)

$(NAME): $(DIROBJS)
	@printf 'Compiling %s binaries : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@gcc -shared -o $(NAME) $^
	@printf 'Compiling %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@ln -s $(NAME) $(LS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf obj
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

fclean: clean
	@rm -rf $(NAME) $(LS)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

re: fclean all

test: re
	@$(CC) $(CFLAGS) -o test main.c -L . $(NAME) $(HEAD) -g
	@./test
	@rm -rf ./test ./test.dSYM/

.PHONY: all clean fclean re