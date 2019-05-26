/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 19:31:48 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_kosty = 0;



static void		first_three(t_stack *a, t_stack *b, t_stack *sorted_stack)
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





void	new_sort(t_stack **a, t_stack **sorted_stack)
{
	t_stack *b;
	int i;
	int pos;
	int rot;

	b = malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		i = 0;
		count_rotops(b);
		allign(*a, b);
		pos = find_min_ops(b);
		rot = get_rot(b, pos);
		while (b->head && i++ < pos)
		{
			if (rot == 1)
			{
				ft_printf("rb ");
				g_kosty++;
				b->head->count--;
				rotate(&b);
			}
			else if (rot == 2)
			{
				ft_printf("rrb ");
				b->head->count--;
				g_kosty++;
				reverse_rotate(&b);
			}
			count_rotops(b);
			allign(*a, b);
			pos = find_min_ops(b);
		}
		rot = get_rot(*a, b->head->neighb_pos);
		i = 0;
		b_head->count--;
		while (i++ < b_head->count)
			if (rot == 1)
			{
				pf("ra ");
				g_kosty++;
				rotate(a);
			}
			else
			{
				pf("rra ");
				reverse_rotate(a);
				g_kosty++;
			}
		pf("pa ");
		g_kosty++;
		push(a, &b);
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
