/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:15:02 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:09:13 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_vals(t_stack *orig_stack, t_stack *sorted_stack)
{
	t_st_node	*node;
	t_st_node	*curr;
	int			i;
	int			j;

	curr = sorted_stack->head;
	i = 0;
	node = orig_stack->head;
	orig_stack->max = sorted_stack->tail->data;
	orig_stack->min = sorted_stack->head->data;
	orig_stack->mid = get_data_at(sorted_stack, (sorted_stack->size / 2) - 1);
	while (sorted_stack->size && curr != NULL)
	{
		curr->sort_pos = i;
		++i;
		curr = curr->next;
	}
	sort_pos(orig_stack, sorted_stack);
}
