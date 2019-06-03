/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:21:16 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 14:23:19 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void perform_flag1(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int rot;
	int pos;
	int i;

	rot = get_rr(b, pos_b);
	pos = get_rot(b, pos_b);
	i = get_data_at(a, pos_a);
	while (rot-- > 0)
		rotate_both(&a, &b);
	while (a->head->data != i)
		if (pos_a <= a->size / 2)
			rotate(&a);
		else
			reverse_rotate(&a);
	while (pos-- > 0)
		rotate(&b);
}

void perform_flag2(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int pos;
	int i;
	int rev;

	pos = get_rrr(b, pos_b);
	i = get_data_at(a, pos_a);
	rev = get_rev(b, pos_b);
	while (pos-- > 0)
		rrotate_both(&a, &b);
	while (a->head->data != i)
		if (pos_a <= a->size / 2)
			rotate(&a);
		else
			reverse_rotate(&a);
	while (rev-- > 0)
		reverse_rotate(&b);
}

void perform_flag3(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int i;
	int rev;

	rev = get_rev(b, pos_b);
	i = get_data_at(a, pos_a);
	while (pos_b > 0 && rev-- > 0)
		reverse_rotate(&b);
	while (a->head->data != i)
	{
		if (pos_a <= a->size / 2)
			rotate(&a);
		else
			reverse_rotate(&a);
	}
}

void perform_flag4(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int i;
	int rot;
	
	rot = get_rot(b, pos_b);
	i = get_data_at(a, pos_a);
	while (pos_b > 0 && rot-- > 0)
		rotate(&b);
	while (a->head->data != i)
	{
		if (pos_a <= a->size / 2)
			rotate(&a);
		else
			reverse_rotate(&a);
	}
}
