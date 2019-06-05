/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:45:52 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 12:40:26 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_rot(t_stack *a, int pos)
{
	t_st_node	*node;

	node = a->head;
	while (node && node->pos != pos)
		node = node->next;
	if (node)
		return (node->rot);
	return (-1);
}

int			get_rr(t_stack *a, int pos)
{
	t_st_node	*node;

	node = a->head;
	while (node && node->pos != pos)
		node = node->next;
	if (node)
		return (node->rr);
	return (-1);
}
