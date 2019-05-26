/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 19:52:59 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_kosty = 0;



static void		first_three(t_stack *a, t_stack *b, t_stack *sorted_stack)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (a->size)
	{
		if (a->head->kisa == 1)
		{
			if (i > a->size)
				break;
			rotate(&a);
			count++;
			a->tail->kisa = 1;
			i++;
			g_kosty++;
		}
		else
		{
			count++;
			push(&b, &a);
			g_kosty++;
		}
	}
	pf("\n COUNT : %d\n", count);
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
