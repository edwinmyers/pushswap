/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:43:11 by nparker           #+#    #+#             */
/*   Updated: 2019/06/05 13:10:25 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_pos(t_stack *orig_stack, t_stack *sort_stack)
{
	t_st_node		*curr_i;
	t_st_node		*curr_j;
	int				i;

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
