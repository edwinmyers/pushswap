/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:15:02 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 14:15:11 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_pos(t_stack *orig_stack, t_stack *sort_stack)
{
	t_st_node		*curr_i;
	t_st_node		*curr_j;
	int			i;

	i = 0;
	curr_i = orig_stack->head;
	curr_j = sort_stack->head;
	while (i < orig_stack->size)
	{
		curr_j = sort_stack->head;
		while (curr_j != NULL)
		{
			if (curr_i->data == curr_j->data)
				curr_i->sort_pos = curr_j->sort_pos;
			curr_j = curr_j->next;
		}
		i++;
		curr_i = curr_i->next;
	}
}

void init_list(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	stack->mid = 0;
}

void set_vals(t_stack *orig_stack, t_stack *sorted_stack)
{
	t_st_node *node;
	t_st_node *curr;
	int i;
	int j;

	curr = sorted_stack->head;
	i = 0;
	node = orig_stack->head;
	orig_stack->max = sorted_stack->tail->data;
	orig_stack->min = sorted_stack->head->data;
	orig_stack->mid = get_data_at(sorted_stack, (sorted_stack->size / 2)- 1);
	while (sorted_stack->size && curr != NULL)
	{
		curr->sort_pos = i;
		++i;
		curr = curr->next;
	}
	sort_pos(orig_stack, sorted_stack);
}
