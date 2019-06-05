/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_neighb_by_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:18:15 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 12:22:08 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_neighb_by_pos(t_stack *a, int pos)
{
	t_st_node	*node;

	node = a->head;
	while (node && node->pos != pos)
		node = node->next;
	return (node->neighb_pos);
}

int				get_min_sort_pos(int *arr, int size)
{
	int			min_pos;
	int			i;

	i = -1;
	min_pos = arr[0];
	while (++i < size)
	{
		if (min_pos > arr[i])
			min_pos = arr[i];
	}
	return (min_pos);
}
