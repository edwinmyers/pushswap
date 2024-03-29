/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:46:26 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 12:19:48 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_count_by_origpos(t_stack *stack, int pos)
{
	t_st_node	*temp;

	temp = stack->head;
	while (temp && temp->sort_pos != pos)
		temp = temp->next;
	if (temp)
		return (temp->count);
	else
		return (-1);
}
