/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:43:53 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/01 16:26:36 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define b_hdata b->head->data
#define a_hdata a->head->data
#define a_tdata a->tail->data


void count_rrs(t_st_node *a, t_st_node *b)
{
	int mixa_sum;
	int mixb_sum;
	int rot_sum;
	int rev_sum;

	b->rr = ft_min(a->rot, b->rot);
	b->rrr = ft_min(a->rev, b->rev);
	rot_sum = b->rr + (ft_max(a->rot, b->rot) - b->rr);
	rev_sum = b->rrr + (ft_max(a->rev, b->rev) - b->rrr);
	mixa_sum = a->rot + b->rev;
	mixb_sum = b->rot + a->rev;
	if (mixa_sum <= rev_sum && mixa_sum <= rot_sum && mixa_sum <= mixb_sum)
	{
		b->rr = 0;
		b->rrr = 0;
		b->count = mixa_sum;
		b->flag = 3;
	}
	else if (mixb_sum <= rev_sum && mixb_sum <= rot_sum && mixb_sum <= mixa_sum)
	{
		b->rr = 0;
		b->rrr = 0;
		b->count = mixb_sum;
		b->flag = 4;
	}
	else if (rot_sum <= rev_sum && rot_sum <= mixa_sum && rot_sum <= mixb_sum)
	{
		b->rrr = 0;
		a->rot -= b->rr;
		b->count = rot_sum;
		b->rot -= b->rr;
		b->rev = 1;
		a->rev = 1;
		b->flag = 1;
	}
	else if (rev_sum <= rot_sum && rev_sum <= mixa_sum && rev_sum <= mixb_sum)
	{
		b->rev -= b->rrr;
		a->rev -= a->rrr;
		b->rot = 0;
		a->rot = 0;
		b->count = rev_sum;
		b->rr = 0;
		b->flag = 2;
	}
}

int		get_min_sort_pos(int *arr, int size)
{
	int min_pos;
	int i;

	i = 0;
	min_pos = arr[0];
	while (i < size)
	{
		if (min_pos > arr[i])
			min_pos = arr[i];
		i++;
	}
	return (min_pos);
}

int		find_neighb(t_stack *a, int sort_pos)
{
	t_st_node	*node;
	int			min_pos[a->size];
	int i;
	int min;

	i = 0;
	arr_zero(min_pos, a->size);
	node = a->head;
	min = node->sort_pos;
	while (node)
	{
		if (node->sort_pos > sort_pos)
			min_pos[i++] = node->sort_pos;
		node = node->next;
	}
	if (i > 1)
		min = get_min_sort_pos(min_pos, i);
	else if (i == 0)
		min = sort_pos;
	else
		min = min_pos[0];
	return (get_pos_by_sortpos(a, min));
}

void count_rotops(t_stack *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->size)
	{
		set_rot(a, i, i);
		i++;
	}
	i = 0;
	j = a->size;
	while (i < a->size)
	{
		set_rev(a, i, j--);
		i++;
	}
}

void	allign(t_stack *a, t_stack *b)
{
	int i;
	t_st_node *a_node;
	t_st_node *b_node;
	int n;

	b_node = b->head;
	while (b_node)
	{
		i = 0;
		a_node = a->head;
		n =	find_neighb(a, b_node->sort_pos);
		while (i++ < n)
			a_node = a_node->next;
		b_node->neighb_pos = a_node->pos;
		a_node->rot = n;
		a_node->rev = a->size - n;
		if (a_node->pos > 0 && b_node->pos > 0)
			count_rrs(a_node, b_node);
		else if (a_node->pos == 0)
		{
			b_node->rr = 0;
			b_node->rrr = 0;
			b_node->count  = ft_min(a_node->rot, a_node->rev) + ft_min(b_node->rot, b_node->rev);
			if (b_node->rot <= b_node->rev)
				b_node->flag = 4;
			else
				b_node->flag = 3;
		}
		else if (b_node->pos == 0)
		{
			b_node->rr = 0;
			b_node->rrr = 0;
			b_node->count = ft_min(b_node->rot, b_node->rev) + ft_min(a_node->rot, a_node->rev);
			if (a_node->rot <= a_node->rev)
				b_node->flag = 4;
			else
				b_node->flag = 3;
		}
		b_node = b_node->next;
	}
}

int				find_min_ops(t_stack *b)
{
	t_st_node	*node;
	int			min;
	int			pos;

	min = b->head->count;
	node = b->head;
	pos = b->head->pos;
	while (node)
	{
		if (min > node->count)
		{
			min = node->count;
			pos = node->pos;
		}
		node = node->next;
	}
	return (pos);
}
