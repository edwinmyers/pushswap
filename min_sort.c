/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:02:35 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/06 16:19:53 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_last_three(t_stack **a, int flag)
{
	int		i;

	i = 0;
	while (i++ < A_SIZE)
	{
		if ((*a)->head->data > A_NEXT->data && (*a)->head > A_TAIL)
			rotate(a, flag == 0 ? 0 : 1);
		if ((*a)->head->data > A_NEXT->data)
			swap_st(a, flag == 0 ? 0 : 1);
		while ((*a)->head->data > A_TAIL->data)
			reverse_rotate(a, flag == 0 ? 0 : 1);
		if (A_NEXT->data > A_TAIL->data)
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
	while (A_SIZE > 3)
	{
		pos = find_min(*a, &min, A_SIZE);
		if (pos > A_SIZE / 2)
			while ((*a)->head->data != min)
				reverse_rotate(a, flag == 0 ? 0 : 1);
		else
			while ((*a)->head->data != min)
				rotate(a, flag == 0 ? 0 : 1);
		push(&b, a, flag == 0 ? 0 : 2);
	}
	sort_last_three(a, flag);
	while (b->size)
		push(a, &b, flag == 0 ? 0 : 1);
	free(b);
	if (!check_sort(*a))
		terminate("MINSORT FUCK", 2);
}
