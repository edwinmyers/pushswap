# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nparker <nparker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 17:22:58 by nparker           #+#    #+#              #
#    Updated: 2019/06/06 15:58:46 by nparker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

FLAGS := -Wall -Wextra -Werror -c -g

NAME := libft.a

SOURCES_DIR := ./
OBJECTS_DIR := ./

SOURCES := ft_memset.c\
	ft_abs.c\
	ft_arr2alloc.c\
	ft_arr2free.c\
	ft_count_lines.c\
	ft_countwords.c\
	ft_free2dmass.c\
	ft_hex_to_dec.c\
	ft_max.c\
	ft_min.c\
	ft_pow.c\
	ft_pushback.c\
	ft_vec_create.c\
	ft_vec_push_back.c\
	ft_vec_resize.c\
	ft_vec_at.c\
	get_next_line.c\
	gnl_with_eol.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strrchr.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strlcat.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstlen.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstdel_begin.c\
	ft_lstmap.c\
	ft_strndup.c

INCLUDES := libft.h

OBJECTS := $(SOURCES:.c=.o)
SOURCES := $(addprefix $(SOURCES_DIR),$(SOURCES))
OBJECTS := $(addprefix $(SOURCES_DIR), $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	$(CC) $(FLAGS) -I $(INCLUDES) $< -o $@
clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(OBJECTS)
	@rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean
