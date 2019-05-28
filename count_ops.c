/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:43:53 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/28 19:21:25 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define b_hdata b->head->data
#define a_hdata a->head->data
#define a_tdata a->tail->data


void count_min(t_st_node *a, t_st_node *b, int asize, int bsize)
{
	int a_min;
	int b_min;

	a->rr = ft_min(a->rot, b->rot);
	b->rr = a->rr;
	if (a->pos >= asize / 2) 
		a->rrr = ft_min(a->rev, b->rev);
	else
		a->rrr = -0;
	if (b->pos >= bsize / 2)
		b->rrr = ft_min(a->rev, b->rev);
	else
		b->rrr = 0;
	a_min = a->pos < asize / 2 ? a->rot - a->rr : a->rev - a->rrr;
	b_min = b->pos < bsize / 2 ? b->rot - b->rr : b->rev - b->rrr;
	b->count = a->rr + a_min + b_min;
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
	if (a->size > 3)
	{
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
	else
	{
		set_rot(a, 0, 0);
		set_rot(a, 1, 1);
		set_rev(a, 2, 1);
	}
}

void	allign(t_stack *a, t_stack *b)
{
	int i;
	t_st_node *a_node;
	t_st_node *b_node;
	int n;
	int count;

	count = 0;
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
		count_min(a_node, b_node, a->size, b->size);
		b_node = b_node->next;
		count++;
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
