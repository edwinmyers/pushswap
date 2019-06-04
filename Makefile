# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nparker <nparker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 12:33:04 by nparker           #+#    #+#              #
#    Updated: 2019/06/04 13:47:12 by nparker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

FLAGS := -Wall -Wextra -Werror

NAME_PUSH := push_swap

NAME_CHECK := checker

LIB_DIR	:= libftprintf
LIBLINK	:= -L$(LIB_DIR) -lftprintf
LIB := $(LIB_DIR)/libftprintf.a

SRC_DIR := ./

OBJ_DIR := objects

SOURCE_PUSH :=	ft_del_node.c\
			sort_pos.c\
			set_vals.c\
			init_list.c\
			ft_lstadd_at_head.c\
			ft_lstadd_at_tail.c\
			ft_newnode.c\
			push.c\
			reverse_rotate_both.c\
			reverse_rotate.c\
			rotate_both.c\
			rotate.c\
			swap_both.c\
			swap_st.c\
			assign_pos.c\
			get_data_at.c\
			parse.c\
			validate.c\
			ft_strtoll.c\
			min_sort.c\
			find_edge.c\
			new_sort.c\
			get_node.c\
			set_count.c\
			get_count.c\
			stack_dup.c\
			set_rot.c\
			get_rot.c\
			count_ops.c\
			get_pos_by_sortpos.c\
			get_neighb_by_pos.c\
			set_rev.c\
			get_rev.c\
			get_flag.c\
			calculate_count.c\
			perform_flags.c\
			push_swap.c\
			terminate.c\

SOURCE_CHECK := checker.c\
				sort_pos.c\
				set_vals.c\
				init_list.c\
				get_data_at.c\
				ft_lstadd_at_head.c\
				ft_lstadd_at_tail.c\
				ft_newnode.c\
				ft_del_node.c\
				validate.c\
				push.c\
				reverse_rotate_both.c\
				reverse_rotate.c\
				rotate_both.c\
				rotate.c\
				swap_both.c\
				swap_st.c\
				parse.c\
				terminate.c\
				ft_strtoll.c\
				assign_pos.c\

OBJECTS_PUSH := $(SOURCE_PUSH:.c=.o)
SRCS_PUSH := $(addprefix $(SRC_DIR), $(SOURCE_PUSH))
OBJS_PUSH := $(addprefix $(OBJ_DIR)/, $(SOURCE_PUSH:.c=.o))

OBJECTS_CHECK := $(SOURCE_CHECK:.c=.o)
SRCS_CHECK := $(addprefix $(SRC_DIR), $(SOURCE_CHECK))
OBJS_CHECK := $(addprefix $(OBJ_DIR)/, $(SOURCE_CHECK:.c=.o))

all: directory $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH): $(OBJ_DIR) $(LIB) $(OBJS_PUSH)
	@$(CC) $(FLAGS) -g -o $@ $(OBJS_PUSH) $(LIBLINK)

$(NAME_CHECK): $(OBJ_DIR) $(LIB) $(OBJS_CHECK)
	@$(CC) $(FLAGS) -g -o $@ $(OBJS_CHECK) $(LIBLINK)

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