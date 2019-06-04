/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 14:36:47 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define POS_B pos[1]
#define POS_A pos[0]


static void		first_three(t_stack *a, t_stack *b, t_stack *sorted_stack)
{
	int i;	
		
	while (a->size != 3)
	{
		if (a->head->data != a->max && a->head->data != a->min && a->head->data != a->mid)
			push(&b, &a, 2);
		else
			rotate(&a, 1);	
	}
	if (a->head->data == a->max && a->head->next->data == a->mid)
		swap_st(&a, 1);
	else if (a->head->data == a->min && a->head->next->data == a->max)
	{
		swap_st(&a, 1);
		reverse_rotate(&a, 1);
	}
	else if (a->head->data == a->mid && a->head->next->data == a->min)
	{
		swap_st(&a, 1);
		rotate(&a, 1);
	}
	else if (a->head->data == a->max && a->head->next->data == a->min)
		reverse_rotate(&a, 1);
	else if (a->head->data == a->min && a->head->next->data == a->mid)
		rotate(&a, 1);
}

static	void	normalize_stack(t_stack *a)
{
	if (find_min(a, &a->min, a->size) > a->size / 2)
		while (find_min(a, &a->min, a->size) != 0)			
		reverse_rotate(&a, 1);
	else
		while (find_min(a, &a->min, a->size) != 0)
		rotate(&a, 1);
}

void	new_sort(t_stack **a, t_stack **sorted_stack)
{
	t_stack *b;
	int pos[2];

	b = (t_stack*)malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		count_rotops(b);
		count_rotops(*a);
		allign(*a, b);
		POS_B = find_min_ops(b);
		POS_A = get_neighb_by_pos(b, POS_B);
		if (get_flag(b, POS_B) == 1)
			perform_flag1(*a, b, POS_A, POS_B);
		else if (get_flag(b, POS_B) == 2)
			perform_flag2(*a, b, POS_A, POS_B);
		else if (get_flag(b, POS_B) == 3)
			perform_flag3(*a, b, POS_A, POS_B);
		else if (get_flag(b, POS_B) == 4)
			perform_flag4(*a, b, POS_A, POS_B);
		push(a, &b, 1);
	}
	normalize_stack(*a);
	free(b);
}
