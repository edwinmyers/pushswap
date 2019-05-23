/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/23 17:28:46 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int kost = 0;



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
			kost += 1;
			ft_printf("ra ");
		}
		else
		{
			push(&b, &a);
			kost += 1;
			ft_printf("pb ");
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
		if (b_orig_pos > b_tail->orig_pos)
		{
			kost++;
			reverse_rotate(&b);
		}
		else if (b_orig_pos < a_orig_pos)
		{
			kost++;
			push(a, &b);
		}
		else if (b->size > 1 && b_next->orig_pos < a_orig_pos)
		{
			kost++;
			swap_st(&b);
		}
		else if (b_orig_pos < a_next->orig_pos)
		{
			kost+=2;
			push(a, &b);
			swap_st(a);
		}
		// else if (b_orig_pos > a_tail->orig_pos)
		// {
		// 	push(a, &b);
		// 	rotate(a);
		// 	kost+=2;
		// }
		else 
			rotate(a);
	
	}
	if (find_min(*a, &(*a)->min, a_size) > a_size / 2)
		while (find_min(*a, &(*a)->min, a_size) != 0)
		{
			ft_printf("rra ");			
			reverse_rotate(a);
			kost += 1;
		}
	else
		while (find_min(*a, &(*a)->min, a_size) != 0)
		{
			ft_printf("ra ");
			rotate(a);
			kost += 1;
		}
		ft_printf("\n|new_sort : %d |\n", kost);
	// if (!check_sort(*a))
	// 	exit(EXIT_FAILURE);
}