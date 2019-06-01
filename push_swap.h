/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:32:37 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/31 18:16:46 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libftprintf/source/ft_printf.h"
# include "Libftprintf/libft/libft.h"

#define pf ft_printf
#define a_head (*a)->head
#define a_next (*a)->head->next 
#define a_tail (*a)->tail
#define a_size (*a)->size
#define a_sort_pos (*a)->head->sort_pos
#define a_count (*a)->head->count
#define b_head  b->head
#define b_next  b->head->next
#define b_tail b->tail
#define b_sort_pos b->head->sort_pos
#define b_count b->head->count
#define b_flag b->head->flag;

typedef struct			s_stack_node
{
	struct s_stack_node *next;
	int data;
	int data_size;
	int pos;
	int sort_pos;
	int count;
	int rot;
	int rev;
	int rrr;
	int rr;
	int flag;
	int neighb_pos;
	short kisa;
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
void        ft_lstadd_at_head(t_stack **alst, t_st_node *node);
void		ft_lstadd_at_tail(t_stack **alst, t_st_node *node);
t_st_node	*ft_newnode(int data, size_t data_size, int sort_pos);
int         ft_del_node(t_stack **alst);
void		push(t_stack **stack_dst, t_stack **stack_src);
void		push_with_pos(t_stack **stack_dst, t_stack **stack_src, t_stack **sorted_stack);
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
int find_median(t_stack *a);
void quick_sort(t_stack **a, t_stack **b, int n, int flag);
void		sort_last_three(t_stack **a);
void		new_sort(t_stack **a, t_stack **sorted_stack);
void		sort_pos(t_stack *orig_stack, t_stack *sort_stack);
int			find_sort_pos(t_stack *a, int sort_pos);
int			get_pos_by_data(t_stack *stack, int data);
t_st_node	*get_node_by_pos(t_stack *stack, int pos);
void set_count_by_currpos(t_stack *stack, int pos, int count);
void set_count_by_sort_pos(t_stack *stack, int pos, int count);
int get_count_by_origpos(t_stack *stack, int pos);
t_st_node *get_node_by_origpos(t_stack *stack, int pos);
void kisa(t_stack *stack);
t_stack *stack_dup(t_stack *src);
void set_rot(t_stack *a, int pos, int rot);
void count_rotops(t_stack *a);
void allign(t_stack *a, t_stack *b);
int				find_min_ops(t_stack *b);
int get_rot(t_stack *a, int pos);
int get_pos_by_sortpos(t_stack *a, int sort_pos);
int get_neighb_by_pos(t_stack *a, int pos);
void set_rev(t_stack *a, int pos, int rev);
int get_rev(t_stack *a, int pos);
int get_rr(t_stack *a, int pos);
int get_rrr(t_stack *a, int pos);
int get_flag(t_stack *a, int pos);

#endif