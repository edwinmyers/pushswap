/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:20:22 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/10 18:28:14 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    ft_lstadd_at_tail(t_stack **alst, t_st_node *node)
{
	if((*alst)->head == NULL)
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
