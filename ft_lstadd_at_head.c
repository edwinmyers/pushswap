/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:07:16 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/10 18:23:55 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_lstadd_at_head(t_stack **alst, t_st_node *node)
{
	if((*alst)->head == NULL)
	{
		(*alst)->head = node;
		(*alst)->tail = node;
	}
	else
	{
		node->next = (*alst)->head;
		(*alst)->head = node;
	}
	(*alst)->size += 1;
}
