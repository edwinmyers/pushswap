/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_qsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:26:29 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/17 18:28:01 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_swap(int *a, int *b)
{
	int			temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void			ft_qsort(int *arr, int first, int last)
{
	int i;
	int j;
	int mid;

	i = first;
	j = last;
	mid = (first + last) / 2;
	while (i <= j)
	{
		while (arr[i] < arr[mid])
			++i;
		while (arr[j] > arr[mid])
			--j;
		if (i <= j)
		{
			ft_swap(&arr[i], &arr[j]);
			++i;
			--j;
		}
	}
	if (first < j)
		ft_qsort(arr, first, j);
	if (last > i)
		ft_qsort(arr, i, last);
}
