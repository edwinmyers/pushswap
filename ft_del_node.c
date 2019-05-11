/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:30:51 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 15:23:42 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_del_node(t_stack **alst)
{
    int item;

    item = 0;
	if((*alst)->head == NULL)
	{	
		ft_printf("\nList is Empty ..."); 	
		return (-1);
	}
	else if ((*alst)->size == 1)
	{	
		(*alst)->head = NULL;
		(*alst)->tail = NULL;
	}
	else
	{
		item = (*alst)->head->data;
		(*alst)->tail->next = (*alst)->head->next;
		(*alst)->head = (*alst)->head->next;
	}
	(*alst)->size -= 1;		
	return (item);
}

int delFromTail(List * lp)
{
	Node * temp;
	int i = 0;

	int item = 0;


	if(lp->tail == NULL)
	{	
		printf("\nList is Empty ..."); 	
		return -1;
	}
	else
	{
		temp = lp->head;

		while(temp->next != lp->tail)
		{ temp = temp->next;}

		item = lp->tail->item;

		lp->tail = temp; 
		lp->tail->next = NULL;		
	}	

	return item;
}