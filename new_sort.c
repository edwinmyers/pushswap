/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/18 17:40:25 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_kosty = 0;

static void		first_three(t_stack *a, t_stack *b)
{

	while (a->size != 3)
	{
		if (a->head->data != a->max && a->head->data != a->min && a->head->data != a->mid)
		{
			ft_printf("pb ");
			push(&b, &a);
			g_kosty += 1;
		}
		else
		{
			ft_printf("ra ");
			rotate(&a);	
			g_kosty += 1;
		}
	}
	if (a->head->data == a->max && a->head->next->data == a->mid)
	{	
		swap_st(&a);
		ft_printf("sa ");
		g_kosty += 1;
	}
	else if (a->head->data == a->min && a->head->next->data == a->max)
	{
		ft_printf("sa ");
		ft_printf("rra ");
		swap_st(&a);
		reverse_rotate(&a);
		g_kosty += 2;
	}
	else if (a->head->data == a->mid && a->head->next->data == a->min)
	{
		ft_printf("sa ");
		ft_printf("ra ");
		swap_st(&a);
		rotate(&a);
		g_kosty += 2;
	}
	else if (a->head->data == a->max && a->head->next->data == a->min)
	{
		ft_printf("rra ");
		reverse_rotate(&a);
		g_kosty += 1;
	}
	else if (a->head->data == a->min && a->head->next->data == a->mid)
	{
		ft_printf("ra ");
		rotate(&a);
		g_kosty += 1;
	}
}


void	new_sort(t_stack **a)
{
	t_stack *b;
	int i;
	
	i = 0;
	b = malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b);
	while (b->size)
	{
		if (b_head < a_head && b_head > a_tail)
		{
			ft_printf("pa ");
			push(a, &b);
			g_kosty += 1;
		}
		else if (b->size > 1 && b_head_next < a_head && b_head_next > a_tail)
		{
			ft_printf("sb ");
			ft_printf("pa ");
			swap_st(&b);
			push(a, &b);
			g_kosty += 2;
		}
		else if (b_tail < a_head && b_tail > a_head)
		{
			ft_printf("rrb ");
			ft_printf("pa ");
			reverse_rotate(&b);
			push(a, &b);
			g_kosty += 2;
		}
		else
		{
			ft_printf("ra ");
			rotate(a);
			g_kosty += 1;
		}
	}
	if (find_min(*a, &(*a)->min, a_size) > a_size / 2)
		while (find_min(*a, &(*a)->min, a_size) != 0)
		{
			ft_printf("rra ");			
			reverse_rotate(a);
			g_kosty += 1;
		}
	else
		while (find_min(*a, &(*a)->min, a_size) != 0)
		{
			ft_printf("ra ");
			rotate(a);
			g_kosty += 1;
		}
		ft_printf("\n|new_sort : %d |\n", g_kosty);
}