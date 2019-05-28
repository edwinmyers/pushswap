/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:13:27 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 20:50:10 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int kostyan = 0;

void quick_sort(t_stack **a, t_stack **b, int n, int flag)
{
	int i;
	int median;

	if (n < 2)
		return ;
	i = 0;
	median = find_median(*a);
	i = 0;
	n = a_size;
	while (i++ < n)
	{
		if (a_head->data <= median)
		{
			push(b, a);
			ft_printf("pb ");
			kostyan++;
		}
		else
		{
			kostyan++;
			ft_printf("ra ");
			rotate(a); 
		}
	}
	i = 0;
	n = (*b)->size;
	median = find_median(*b);
	while (i++ < n)
	{
		if ((*b)->head->data <= median)
		{
			kostyan++;
			push(a, b);
			ft_printf("pa ");
		}
		else
		{
			ft_printf("rb ");
			rotate(b);
			kostyan++; 
		}
	}
	while ((*b)->size)
		push(a, b);
	if (!check_sort(*a))
		quick_sort(a, b, a_size, 1);
	ft_printf("\n|QuickSort: %d|\n", kostyan);
}
