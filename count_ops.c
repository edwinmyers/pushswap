/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:43:53 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 19:02:46 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define b_hdata b->head->data
#define a_hdata a->head->data
#define a_tdata a->tail->data

int get_min_sort_pos(int *arr, int size)
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
	min = i > 1 ? get_min_sort_pos(min_pos, i) : min_pos[0];
	return(get_pos_by_sortpos(a, min));
}

void count_rotops(t_stack *a)
{
	int i;
	int j;

	i = 0;
	if (a->size > 3)
	{
		j = 1;
		while (i < a->size / 2)
		{
			set_rot(a, i, 1);
			set_count_by_currpos(a, i++, j++);
		}
		i = a->size / 2;
		j = a->size / 2 + 1;
		while (i < a->size)
		{
			set_rot(a, i, 2);
			set_count_by_currpos(a, i++, j--);
		}
	}
	else
	{
		set_count_by_currpos(a, 0, 1);
		set_count_by_currpos(a, 1, 2);
		set_count_by_currpos(a, 2, 2);
	}
}

void	allign(t_stack *a, t_stack *b)
{
	int i;
	t_st_node *a_node;
	t_st_node *b_node;
	i = 0;
	int n;
	
	b_node = b->head;
	while (b_node)
	{
		i = 0;
		a_node = a->head;
		n =	find_neighb(a, b_node->sort_pos);
		while (i++ < n)
		{
			b_node->count += n <= (a->size / 2) ? 1 : 0;
			a_node = a_node->next;
		}
		b_node->count += a_node->pos > (a->size / 2) ? a->size - n : 0;
		b_node->neighb_pos = a_node->pos;
		a_node->rot = a_node->pos > (a->size / 2) ? 2 : 1;
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
