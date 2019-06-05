/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:40:05 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:11:34 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*stack_dup(t_stack *src)
{
	t_stack		*new;
	t_st_node	*temp;

	temp = src->head;
	new = (t_stack *)malloc(sizeof(t_stack));
	init_list(new);
	while (temp)
	{
		ft_lstadd_at_tail(&new, ft_newnode(temp->data,
		sizeof(int), temp->sort_pos));
		temp = temp->next;
	}
	return (new);
}
