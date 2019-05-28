/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:20:56 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/28 18:42:43 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

#define MAS 10
#define MAXP 10
#define MINP 0

int     main () {
     int i, j;
     int arr[MAS];
     int buf;
     int l;
 
    j = 0;
    l = 0;
    i = 0;
    buf = 0;
    srand(time(NULL));
    while (i < MAS) {
          buf = MINP + rand() % (MAXP - MINP);
          arr[i] = buf;
          ++i;
    }
    i = 0;
    srand(time(NULL));
    while (i < MAS)
    {
        j = i + 1;
        while (j < MAS)
        {
        if (arr[i] == arr[j])
        {
        arr[j] = MINP + rand() % (MAXP - MINP);
        l = 1;
        break ;
        }
        ++j;
        }
                if (l == 1)
        {
            i = 0;
            l = 0;
            continue ;
        }
        ++i;
    }
    // printf("{");
     i = 0;
     while (i < MAS)
     {
        //  if (i == MAS - 1)
        //  {
        //  printf("%d};", arr[i++]);
        //  break ;
        //  }
        printf("%d ", arr[i++]);
     }
}