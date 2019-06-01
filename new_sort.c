/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:17:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/01 16:32:05 by vice-wra         ###   ########.fr       */
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
			push(&b, &a);
			g_kosty += 1;
		}
		else
		{
			rotate(&a);	
			g_kosty += 1;
		}
	}
	if (a->head->data == a->max && a->head->next->data == a->mid)
	{	
		swap_st(&a);
		g_kosty += 1;
	}
	else if (a->head->data == a->min && a->head->next->data == a->max)
	{
		swap_st(&a);
		reverse_rotate(&a);
		g_kosty += 2;
	}
	else if (a->head->data == a->mid && a->head->next->data == a->min)
	{
		swap_st(&a);
		rotate(&a);
		g_kosty += 2;
	}
	else if (a->head->data == a->max && a->head->next->data == a->min)
	{
		reverse_rotate(&a);
		g_kosty += 1;
	}
	else if (a->head->data == a->min && a->head->next->data == a->mid)
	{
		rotate(&a);
		g_kosty += 1;
	}
	// pf("\n");
}

void perform_flag1(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int rot;
	int pos;
	int i;

	rot = get_rr(b, pos_b);
	pos = get_rot(b, pos_b);
	i = get_data_at(a, pos_a);
	while (rot-- > 0)
	{
		// pf("rr ");
		g_kosty++;
		rotate_both(&a, &b);
	}
	while (a->head->data != i)
	{
		g_kosty++;
		if (pos_a <= a->size / 2)
		{
			// pf("ra ");
			rotate(&a);
		}
		else
		{
			// pf("rra ");
			reverse_rotate(&a);
		}
	}
	while (pos-- > 0)
	{
		// pf("rb ");
		g_kosty++;
		rotate(&b);
	}
}

void perform_flag2(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int pos;
	int i;
	int rev;

	pos = get_rrr(b, pos_b);
	i = get_data_at(a, pos_a);
	rev = get_rev(b, pos_b);
	while (pos-- > 0)
	{
		// pf("rrr ");
		g_kosty++;
		rrotate_both(&a, &b);
	}
	while (a->head->data != i)
	{
		g_kosty++;
		if (pos_a <= a->size / 2)
		{
			// pf("ra ");
			rotate(&a);
		}
		else
		{
			// pf("rra ");
			reverse_rotate(&a);
		}
	}
	while (rev-- > 0)
	{
		// pf("rrb ");
		g_kosty++;
		reverse_rotate(&b);
	}
}
void perform_flag3(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int i;
	int rev;

	rev = get_rev(b, pos_b);
	i = get_data_at(a, pos_a);
	while (pos_b > 0 && rev-- > 0)
	{
		// pf("rrb ");
		g_kosty++;
		reverse_rotate(&b);
	}
	while (a->head->data != i)
	{
		g_kosty++;
		if (pos_a <= a->size / 2)
		{
			// pf("ra ");
			rotate(&a);
		}
		else
		{
			// pf("rra ");
			reverse_rotate(&a);
		}
	}
}

void perform_flag4(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int i;
	int rot;
	
	rot = get_rot(b, pos_b);
	i = get_data_at(a, pos_a);
	while (pos_b > 0 && rot-- > 0)
	{
		g_kosty++;
		// pf("rb ");
		rotate(&b);
	}
	while (a->head->data != i)
	{
		g_kosty++;
		if (pos_a <= a->size / 2)
		{
			// pf("ra ");
			rotate(&a);
		}
		else
		{
			// pf("rra ");
			reverse_rotate(&a);
		}
	}
}

void	new_sort(t_stack **a, t_stack **sorted_stack)
{
	t_stack *b;
	int pos_b;
	int pos_a;
	int flag;

	b = malloc(sizeof(t_stack));
	init_list(b);
	first_three(*a, b, *sorted_stack);
	while (b->size)
	{
		count_rotops(b);
		count_rotops(*a);
		allign(*a, b);
		pos_b = find_min_ops(b);
		pos_a = get_neighb_by_pos(b, pos_b);
		flag = get_flag(b, pos_b);
		if (flag == 1)
			perform_flag1(*a, b, pos_a, pos_b);
		else if (flag == 2)
			perform_flag2(*a, b, pos_a, pos_b);
		else if (flag == 3)
			perform_flag3(*a, b, pos_a, pos_b);
		else if (flag == 4)
			perform_flag4(*a, b, pos_a, pos_b);
		g_kosty += 1;
		push(a, &b);
		// ft_printf("pa ");
		// pf("\na->head : %d, a->head->next : %d\n", a_head->data, a_head->next->data);
	}
 	if (find_min(*a, &(*a)->min, a_size) > a_size / 2)
		while (find_min(*a, &(*a)->min, a_size) != 0)
		{
			// ft_printf("rra ");			
			reverse_rotate(a);
			g_kosty += 1;
		}
	else
		while (find_min(*a, &(*a)->min, a_size) != 0)
		{
			// ft_printf("ra ");
			rotate(a);
			g_kosty += 1;
		}
	ft_printf("\n|new_sort : %d|\n", g_kosty);
	if (!check_sort(*a))
		terminate("FUCK\n");
}
