/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:02:35 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/18 17:46:25 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_kostyl = 0;

void sort_last_three(t_stack **a)
{
	int i;

	i = 0;
	while (i++ < a_size)
	{
		if (a_head > a_head_next && a_head > a_tail)
		{
			g_kostyl++;
			rotate(a);
			ft_printf("ra ");			
		}
		if (a_head > a_head_next)
		{
			g_kostyl++;
			ft_printf("sa ");
			swap_st(a);
		}
		while (a_head > a_tail)		
		{
			g_kostyl++;
			ft_printf("rra ");
			reverse_rotate(a);
		}
		if (a_head_next > a_tail)
		{
			g_kostyl+=2;
			ft_printf("sa ");
			swap_st(a);
			ft_printf("raa ");
			rotate(a);
		}	
	}
}

void min_num_sort(t_stack **a)
{
	t_stack *b;
	int min;
	int pos;

	b = malloc(sizeof(t_stack));
	init_list(b);
	while (a_size > 3)
	{
		if (check_sort(*a))
			break;
		pos = find_min(*a, &min, a_size);
		if (pos > a_size / 2)
			while (a_head != min)
			{
				g_kostyl++;
				ft_printf("rra ");
				reverse_rotate(a);
			}
		else
			while (a_head != min)
			{
				ft_printf("ra ");
				g_kostyl++;
				rotate(a);
			}
		ft_printf("pb ");
		push(&b, a);
		g_kostyl++;
	}
	sort_last_three(a);
	while (b->size)
	{
		g_kostyl++;
		ft_printf("pa ");
		push(a, &b);
	}
	ft_printf("\n|min_sort: %d|\n", g_kostyl);
}
