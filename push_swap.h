/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:32:37 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/18 17:46:19 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libftprintf/source/ft_printf.h"
# include "Libftprintf/libft/libft.h"


#define a_head (*a)->head->data 
#define a_head_next (*a)->head->next->data 
#define a_tail (*a)->tail->data
#define a_size (*a)->size
#define b_head  b->head->data 
#define b_head_next  b->head->next->data
#define b_tail b->tail->data

typedef struct			s_stack_node
{
	struct s_stack_node *next;
	int data;
	int data_size;
	int pos;
	int orig_pos;
}						t_st_node;

typedef struct			s_stack
{
	t_st_node *head;
	t_st_node *tail;
	int max;
	int mid;
	int min;
	int size;
}						t_stack;

/*
**          Vice-wra
*/

void		*ft_memcpy(void *dst, const void *src, size_t n);
t_st_node	*ft_newnode(int data, size_t data_size);
void        ft_lstadd_at_head(t_stack **alst, t_st_node *node);
void		ft_lstadd_at_tail(t_stack **alst, t_st_node *node);
int         ft_del_node(t_stack **alst);
void        push(t_stack **stack_a, t_stack **stack_b);
void        swap_st(t_stack **stack);
void        rotate(t_stack **stack);
void        reverse_rotate(t_stack **stack);
void        swap_both(t_stack **stack_a, t_stack **stack_b);
void        rotate_both(t_stack **stack_a, t_stack **stack_b);
int         delfromtail(t_stack **alst);
void        assign_pos(t_stack *stack);
void        rrotate_both(t_stack **stack_a, t_stack **stack_b);
int         find_min(t_stack *a, int *min, int n);
int         get_data_at(t_stack *stack, int pos);
int			check_sort(t_stack *stack);
int         ft_isint(char *str);
int 		ft_isnum(char *str);
int 		ft_ischar(char *str);
void	    check_dup(t_stack *stack);
char        terminate(char *str);
t_stack		*parse_num(int argc, char **argv);
long long   ft_strtoll(const char *str);
void		init_list(t_stack *stack);
void		min_num_sort(t_stack **a);
int			find_median(t_stack *a, int n);
void		quick_sort(t_stack **a, int n);
void		sort_last_three(t_stack **a);
void		new_sort(t_stack **a);


#endif