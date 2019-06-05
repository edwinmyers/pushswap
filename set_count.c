/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:14:40 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:03:10 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_count_by_currpos(t_stack *stack, int pos, int count)
{
	t_st_node	*temp;

	temp = stack->head;
	while (temp && pos-- > 0)
		temp = temp->next;
	if (temp)
		temp->count = count;
}

void		set_count_by_sort_pos(t_stack *stack, int pos, int count)
{
	t_st_node	*temp;

	temp = stack->head;
	while (temp && temp->sort_pos != pos)
		temp = temp->next;
	if (temp)
		temp->count = count;
}
