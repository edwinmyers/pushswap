/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:42:15 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:05:31 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rev(t_stack *a, int pos, int rev)
{
	t_st_node	*node;

	node = a->head;
	while (node && node->pos != pos)
		node = node->next;
	if (node)
		node->rev = rev;
}
