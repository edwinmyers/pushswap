/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/28 17:48:04 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_kosty = 0;


static void		first_three(t_stack *a, t_stack *b, t_stack *sorted_stack)
{
	int i;	
		
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
	int pos_b;
	int rev;
	int rot;
	int pos_a;
	int pos;

	b = malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		i = 0;
		count_rotops(b);
		count_rotops(*a);
		allign(*a, b);
		pos_b = find_min_ops(b);
		pos_a = get_neighb_by_pos(b, pos_b);
		if (get_rev(*a, pos_a) <= get_rot(*a, pos_a) && get_rev(b, pos_b) <= get_rot(b, pos_b))
		{
			rev = ft_min(get_rev(*a, pos_a), get_rev(b, pos_b));
			while (rev-- > 0)
			{
				ft_printf("rrr ");
				rrotate_both(a, &b);
				g_kosty++;
				pos_a = (pos_a + 1)- a_size;
				pos_b = (pos_b + 1) - b->size;			
			}
			pos_a = a_size - pos_a;
			while (pos_a-- > 0)
			{
				ft_printf("rra ");
				g_kosty++;
				reverse_rotate(a);
			}
			pos_b = b->size - pos_b;
			while (pos_b-- > 0)
			{
				g_kosty++;
				ft_printf("rrb ");
				reverse_rotate(&b);
			}
		}
		else if (get_rot(*a, pos_a) < get_rev(*a, pos_a) &&  get_rot(b, pos_b) < get_rev(b, pos_b))
		{
			rot = ft_min(get_rot(*a, pos_a), get_rot(b, pos_b));
			while (rot-- > 0)
			{
				g_kosty++;
				rotate_both(a, &b);
				ft_printf("rr ");
				pos_a--;
				pos_b--;
			}
			while (pos_a-- > 0)
			{
				g_kosty++;
				rotate(a);
				ft_printf("ra ");
			}
			while (pos_b-- > 0)
			{
				g_kosty++;
				ft_printf("rb ");
				rotate(&b);
			}
		}
		else
		{
			if (get_rot(*a, pos_a) <= get_rev(*a, pos_a))
			while (pos_a-- > 0)
			{
				g_kosty++;
				rotate(a);
				ft_printf("ra ");

			}
			else if (get_rev(*a, pos_a) < get_rot(*a, pos_a))
			{
				pos_a = a_size - pos_a;
				while (pos_a-- > 0)
				{
					g_kosty++;
					ft_printf("rra ");
					reverse_rotate(a);
				}
			}
			if (get_rot(b, pos_b) <= get_rev(b, pos_b))
			while (pos_b-- > 0)
			{
				g_kosty++;
				rotate(&b);
				ft_printf("ra ");
			}
			else if (get_rev(b, pos_b) < get_rot(b, pos_b))
			{
				pos_b = b->size - pos_b;
				while (pos_b-- > 0)
				{
					g_kosty++;
					ft_printf("rra ");
					reverse_rotate(&b);
				}
			}
		}
		g_kosty += 1;
		push(a, &b);
		ft_printf("pa ");

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
