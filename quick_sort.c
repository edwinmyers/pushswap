/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:13:27 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/23 18:01:37 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_sort(t_stack **a, int n)
{
	t_stack *b;
	int i;
	int median;
	int len;
	int rot;

	if (n < 2)
		return ;
	i = 0;
	rot = 0;
	len = 0;
	median = find_median(*a);
	while (i++ < n)
	{
		if (a_head->data <= median)
		{
			len++;
			push(&b, a);
			ft_printf("pb ");
		}
		else
		{
			ft_printf("ra ");
			rot++;
			rotate(a); 
		}
	}
    quick_sort(a, a_size);
	quick_sort(&b, b->size);
	
}