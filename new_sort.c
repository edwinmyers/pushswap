/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 14:24:51 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		first_three(t_stack *a, t_stack *b, t_stack *sorted_stack)
{
	int i;	
		
	while (a->size != 3)
	{
		if (a->head->data != a->max && a->head->data != a->min && a->head->data != a->mid)
			push(&b, &a);
		else
			rotate(&a);	
	}
	if (a->head->data == a->max && a->head->next->data == a->mid)
		swap_st(&a);
	else if (a->head->data == a->min && a->head->next->data == a->max)
	{
		swap_st(&a);
		reverse_rotate(&a);
	}
	else if (a->head->data == a->mid && a->head->next->data == a->min)
	{
		swap_st(&a);
		rotate(&a);
	}
	else if (a->head->data == a->max && a->head->next->data == a->min)
		reverse_rotate(&a);
	else if (a->head->data == a->min && a->head->next->data == a->mid)
		rotate(&a);
}

void	new_sort(t_stack **a, t_stack **sorted_stack)
{
	t_stack *b;
	int pos_b;
	int pos_a;

	b = (t_stack*)malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		count_rotops(b);
		count_rotops(*a);
		allign(*a, b);
		pos_b = find_min_ops(b);
		pos_a = get_neighb_by_pos(b, pos_b);
		if (get_flag(b, pos_b) == 1)
			perform_flag1(*a, b, pos_a, pos_b);
		else if (get_flag(b, pos_b) == 2)
			perform_flag2(*a, b, pos_a, pos_b);
		else if (get_flag(b, pos_b) == 3)
			perform_flag3(*a, b, pos_a, pos_b);
		else if (get_flag(b, pos_b) == 4)
			perform_flag4(*a, b, pos_a, pos_b);
		push(a, &b);
	}
 	if (find_min(*a, &(*a)->min, a_size) > a_size / 2)
		while (find_min(*a, &(*a)->min, a_size) != 0)			
			reverse_rotate(a);
	else
		while (find_min(*a, &(*a)->min, a_size) != 0)
			rotate(a);
}
