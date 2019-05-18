/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:19 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/18 17:45:03 by vice-wra         ###   ########.fr       */
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

int find_median(t_stack *a, int n)
{
    int median;
    t_st_node *temp;

	temp = a->head;

	while (temp && n)
	{
		n--;
		temp = temp->next;
	}
	median = temp->data;
    return (median);
}