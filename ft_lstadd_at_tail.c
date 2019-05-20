/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:20:22 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/20 12:46:01 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_at_tail(t_stack **alst, t_st_node *node)
{
	if ((*alst)->head == NULL)
	{
		(*alst)->head = node;
		(*alst)->tail = node;
	}
	else
	{
		(*alst)->tail->next = node;
		(*alst)->tail = (*alst)->tail->next;
	}
	(*alst)->size += 1;
}
