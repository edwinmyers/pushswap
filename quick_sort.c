// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/05/17 17:13:27 by vice-wra          #+#    #+#             */
// /*   Updated: 2019/05/17 18:55:28 by vice-wra         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void quick_sort(t_stack **a, int n)
// {
// 	t_stack *b;
// 	int i;
// 	int median;
// 	int len;
// 	int rot;

// 	if (n == 1)
// 		return ;
// 	i = 0;
// 	rot = 0;
// 	len = 0;
// 	b = malloc(sizeof(t_stack));
// 	init_list(b);
// 	median = find_median(*a, n / 2);
// 	while (i++ < n)
// 	{
// 		if (a_head <= median)
// 		{
// 			len++;
// 			push(&b, a);
// 			ft_printf("pb ");
// 		}
// 		else
// 		{
// 			ft_printf("ra ");
// 			rot++;
// 			rotate(a); 
// 		}
// 	}
// 	i = 0;
// 	while (i++ < rot)
// 	{
// 		ft_printf("rra ");
// 		reverse_rotate(a);
// 	}
// 	while (b->size)
// 	{
// 		ft_printf("pa ");
// 		push(a, &b);
// 	}
// 	if (!check_sort(*a, n))
// 		quick_sort(a, len);
// 	i = 0;
// 	while (i++ < n && n != a_size)
// 		rotate(a);
// 	quick_sort(a, n - len);
	
// }