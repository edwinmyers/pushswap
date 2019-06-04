/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:09:37 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 13:59:09 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_flag1(t_st_node *a, t_st_node *b, int rot_sum)
{
	a->rot -= b->rr;
	b->count = rot_sum;
	b->rot -= b->rr;
	b->flag = 1;
}

void	set_flag2(t_st_node *a, t_st_node *b, int rev_sum)
{
	b->rev -= b->rrr;
	a->rev -= a->rrr;
	b->count = rev_sum;
	b->flag = 2;
}

void	set_flag3(t_st_node *b, int mixa_sum)
{
	b->count = mixa_sum;
	b->flag = 3;
}

void	set_flag4(t_st_node *b, int mixb_sum)
{
	b->count = mixb_sum;
	b->flag = 4;
}

void	calculate_count(t_st_node *a, t_st_node *b)
{
	int mixa_sum;
	int mixb_sum;
	int rot_sum;
	int rev_sum;

	b->rr = ft_min(a->rot, b->rot);
	b->rrr = ft_min(a->rev, b->rev);
	rot_sum = ft_max(a->rot, b->rot);
	rev_sum = ft_max(a->rev, b->rev);
	mixa_sum = a->rot + b->rev;
	mixb_sum = b->rot + a->rev;
	if (mixa_sum <= rev_sum && mixa_sum <= rot_sum && mixa_sum <= mixb_sum)
		set_flag3(b, mixa_sum);
	else if (mixb_sum <= rev_sum && mixb_sum <= rot_sum && mixb_sum <= mixa_sum)
		set_flag4(b, mixb_sum);
	else if (rot_sum <= rev_sum && rot_sum <= mixa_sum && rot_sum <= mixb_sum)
		set_flag1(a, b, rot_sum);
	else if (rev_sum <= rot_sum && rev_sum <= mixa_sum && rev_sum <= mixb_sum)
		set_flag2(a, b, rev_sum);
}
