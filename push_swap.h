/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:32:37 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 16:30:17 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libftprintf/source/ft_printf.h"

typedef struct			s_stack_node
{
    struct s_stack_node *next;
    int data;
    int data_size;
}						t_st_node;

typedef struct			s_stack
{
    t_st_node *head;
    t_st_node *tail;
    int size;
}						t_stack;

/*
**          Vice-wra
*/

void		*ft_memcpy(void *dst, const void *src, size_t n);
t_st_node	*ft_newnode(int data, size_t data_size);
void        ft_lstadd_at_head(t_stack **alst, t_st_node *node);
void		ft_lstdelone(t_st_node **alst, void (*del)(void*, size_t));
int			ft_lstlen(t_st_node *lst);
void		ft_lstadd_at_tail(t_stack **alst, t_st_node *node);
int         ft_del_node(t_stack **alst);
void        push(t_stack **stack_a, t_stack **stack_b);
void        swap_st(t_stack **stack);
void        rotate(t_stack **stack);
void        reverse_rotate(t_stack **stack);
void        swap_both(t_stack **stack_a, t_stack **stack_b);
void        rotate_both(t_stack **stack_a, t_stack **stack_b);
int         delfromtail(t_stack **alst);
void        rrotate_both(t_stack **stack_a, t_stack **stack_b);

#endif