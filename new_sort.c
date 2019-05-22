/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/22 18:17:48 by vice-wra         ###   ########.fr       */
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
			push(&b, &a);
			g_kosty += 1;
			ft_printf("pb ");
		}
	}

}


void	new_sort(t_stack **a, t_stack **sorted_stack)
{
	t_stack *b;
	int count;
	int rot_count;

	rot_count = 0;
	count = 0;
	b = malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		if (a_orig_pos == 0)
			rotate(a);
		else if (get_node_by_origpos(*a, b_orig_pos + 1) && a_orig_pos == b_orig_pos + 1)
			push(a, &b);
		else 
		{
			if (rot_count > b->size)
				break;
			rotate(&b);
			rot_count++;
			set_count_by_orig_pos(b, a_orig_pos - 1, get_count_by_origpos(b, a_orig_pos - 1) + 1);
		}
		
	}	



}