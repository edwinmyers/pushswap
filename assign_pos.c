/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:31:16 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 13:47:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_pos(t_stack *stack)
{
	t_st_node	*temp;
	int			pos;

	pos = 0;
	temp = stack->head;
	while (temp)
	{
		temp->pos = pos;
		pos++;
		temp = temp->next;
	}
	stack->tail->pos = stack->size - 1;
}
