/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/20 19:12:43 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_kosty = 0;

static void		first_three(t_stack *a, t_stack *b, t_stack *sorted_stack)
{
	t_st_node *tmp;
	int size;
	int i;
	size = a->size;
	tmp = a->head;
	
	while (size--)
	{
		if (a->head->kisa == 1)
		{
			rotate(&a);
			g_kosty += 1;
			ft_printf("ra ");
		}
		else
		{
			push_with_pos(&b, &a, &sorted_stack);
			g_kosty += 1;
			ft_printf("pa ");
		}
	}
}


void	new_sort(t_stack **a, t_stack **sorted_stack)
{
	t_stack *b;
	int i;
	
	i = 0;
	b = malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		if (b_head < a_head && b_head > a_tail)
		{
			ft_printf("pa ");
			push_with_pos(a, &b, sorted_stack);
			g_kosty += 1;
		}
		else if (b->size > 1 && b_head_next < a_head && b_head_next > a_tail)
		{
			ft_printf("sb ");
			ft_printf("pa ");
			swap_st(&b);
			push_with_pos(a, &b, sorted_stack);
			g_kosty += 2;
		}
		else if (b_tail < a_head && b_tail > a_tail)
		{
			ft_printf("rrb ");
			ft_printf("pa ");
			reverse_rotate(&b);
			push_with_pos(a, &b, sorted_stack);
			g_kosty += 2;
		}
		else
		{
			
			ft_printf("ra ");
			rotate(a);
			g_kosty += 1;
		}
		// else if (find_orig_pos(*a, b->head->orig_pos) > a_size / 2)
		// {
		// 	ft_printf("rra ");
		// 	reverse_rotate(a);
		// 	g_kosty += 1;
		// }
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