/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:57:55 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:15:14 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rot(t_stack *a, int pos, int rot)
{
	t_st_node	*node;

	node = a->head;
	while (node && node->pos != pos)
		node = node->next;
	if (node)
		node->rot = rot;
}
