/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_int_in_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:51:10 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/23 15:54:17 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int maxnb_inarr(int *arr, int size)
{
    int max;
    int i;

    i = 0;
    max = arr[0];
    while (size-- > 0)
    {
        if (arr[i] > max)
            max = arr[i];
    }


}