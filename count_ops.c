/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:43:53 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 14:15:23 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define b_hdata b->head->data
#define a_hdata a->head->data
#define a_tdata a->tail->data


int		get_min_sort_pos(int *arr, int size)
{
	int min_pos;
	int i;

	i = -1;
	min_pos = arr[0];
	while (++i < size)
	{
		if (min_pos > arr[i])
			min_pos = arr[i];
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

	i = -1;
	while (++i < a->size)
		set_rot(a, i, i);
	i = -1;
	j = a->size;
	while (++i < a->size)
		set_rev(a, i, j--);
}

void	no_need_to_move(t_st_node *a_node, t_st_node *b_node)
{
	b_node->rr = 0;
	b_node->rrr = 0;
	b_node->count  = ft_min(a_node->rot, a_node->rev) + ft_min(b_node->rot, b_node->rev);
	if (a_node->pos == 0)
	{
		if (b_node->rot <= b_node->rev)
		b_node->flag = 4;
		else
		b_node->flag = 3;
	}
	else if (b_node->pos == 0)
	{
		if (a_node->rot <= a_node->rev)
		b_node->flag = 4;
		else
		b_node->flag = 3;
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
			calculate_count(a_node, b_node);
		else
			no_need_to_move(a_node, b_node);
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
