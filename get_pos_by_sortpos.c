/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_by_sortpos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:13:42 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 12:27:30 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pos_by_sortpos(t_stack *a, int sort_pos)
{
	t_st_node	*node;

	node = a->head;
	while (node && node->sort_pos != sort_pos)
		node = node->next;
	return (node->pos);
}
