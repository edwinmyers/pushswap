# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 12:33:04 by nparker           #+#    #+#              #
#    Updated: 2019/05/16 17:20:50 by vice-wra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

FLAGS := -Wall -Wextra -Werror

NAME := push_swap

LIB_DIR	:= libftprintf
LIBLINK	:= -L$(LIB_DIR) -lftprintf 
LIB := $(LIB_DIR)/libftprintf.a

SRC_DIR := ./

OBJ_DIR := objects/

SOURCE :=	ft_del_node.c\
			ft_lstadd_at_head.c\
			ft_lstadd_at_tail.c\
			ft_node_new.c\
			push.c\
			reverse_rotate_both.c\
			reverse_rotate.c\
			rotate_both.c\
			rotate.c\
			swap_both.c\
			swap_st.c\
			assign_pos.c\
			get_data_at.c\
			test.c\

OBJECTS := $(SOURCE:.c=.o)
SRCS := $(addprefix $(SRC_DIR), $(SOURCE))
OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCE:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(LIB) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LIBLINK)

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@$(CC) -g -c $^ -o $@ $(INCLUDES)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: clean all re fclean directory