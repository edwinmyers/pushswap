/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:02:35 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:08:01 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_last_three(t_stack **a, int flag)
{
	int		i;

	i = 0;
	while (i++ < a_size)
	{
		if (a_head->data > a_next->data && a_head > a_tail)
			rotate(a, flag == 0 ? 0 : 1);
		if (a_head->data > a_next->data)
			swap_st(a, flag == 0 ? 0 : 1);
		while (a_head->data > a_tail->data)
			reverse_rotate(a, flag == 0 ? 0 : 1);
		if (a_next->data > a_tail->data)
		{
			swap_st(a, flag == 0 ? 0 : 1);
			rotate(a, flag == 0 ? 0 : 1);
		}
	}
}

void		min_num_sort(t_stack **a, int flag)
{
	t_stack *b;
	int		min;
	int		pos;

	b = (t_stack*)malloc(sizeof(t_stack));
	init_list(b);
	while (a_size > 3)
	{
		pos = find_min(*a, &min, a_size);
		if (pos > a_size / 2)
			while (a_head->data != min)
				reverse_rotate(a, flag == 0 ? 0 : 1);
		else
			while (a_head->data != min)
				rotate(a, flag == 0 ? 0 : 1);
		push(&b, a, flag == 0 ? 0 : 2);
	}
	sort_last_three(a, flag);
	while (b->size)
		push(a, &b, flag == 0 ? 0 : 1);
	free(b);
	if (!check_sort(*a))
		terminate("MINSORT FUCK");
}
