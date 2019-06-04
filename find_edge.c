/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:19 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 13:39:27 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *a, int *min, int n)
{
	t_st_node *temp;
	int pos;

	pos = 0;
	temp = a->head;
	*min = temp->data;
	while (temp && n)
	{
		if (temp->data < *min)
		{
			*min = temp->data;
			pos = temp->pos;
		}
		temp = temp->next;
		n--;
	}
	return (pos);
}

int find_max(t_stack *a, int *max, int n)
{
	t_st_node *temp;
	int pos;

	pos = 0;
	temp = a->head;
	*max = temp->data;
	while (temp && n)
	{
		if (temp->data > *max)
		{
			*max = temp->data;
			pos = temp->pos;
		}
		temp = temp->next;
		n--;
	}
	return (pos);
}

int find_median(t_stack *a)
{
	t_stack *temp;
	int mid;

	temp = stack_dup(a);
	min_num_sort(&temp, 0);
	mid = get_data_at(temp, (temp->size / 2) - 1);
	free(temp);
	return (mid);
}

int find_sort_pos(t_stack *a, int sort_pos)
{
	t_st_node *tmp;

	tmp = a->head;
	if (!a || sort_pos == 0)
		return 0;
	while (tmp)
	{
		if (tmp->sort_pos == (sort_pos + 1) || tmp->sort_pos == (sort_pos - 1))
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (0);
}
