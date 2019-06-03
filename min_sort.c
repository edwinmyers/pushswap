/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:02:35 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 13:33:49 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_last_three(t_stack **a)
{
	int i;

	i = 0;
	while (i++ < a_size)
	{
		if (a_head->data > a_next->data && a_head > a_tail)
			rotate(a);
		if (a_head->data > a_next->data)
			swap_st(a);
		while (a_head > a_tail)		
			reverse_rotate(a);
		if (a_next->data > a_tail->data)
		{
			swap_st(a);
			rotate(a);
		}	
	}
}

void min_num_sort(t_stack **a)
{
	t_stack *b;
	int min;
	int pos;

	b = (t_stack*)malloc(sizeof(t_stack));
	init_list(b);
	while (a_size > 3)
	{
		pos = find_min(*a, &min, a_size);
		if (pos > a_size / 2)
			while (a_head->data != min)
				reverse_rotate(a);
		else
			while (a_head->data != min)
				rotate(a);
		push(&b, a);
	}
	sort_last_three(a);
	while (b->size)
		push(a, &b);
	if (!check_sort(*a))
		terminate("MINSORT ERROR");
}
