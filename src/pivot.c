/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:27:59 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 10:18:50 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

void
	get_appropriate_pivot(t_arr arr, long *small, long* big, t_pvipt input)
{
	long	i;
	int		small_checked;
	long	li;
	long	ri;

	li = 0;
	ri = arr.len - 1;
	small_checked = 0;
	i = 0;
	while (i < arr.len)
	{
		if (!small_checked && arr.ds[i] > input.min)
		{
			li = i;
			small_checked = 1;
		}
		if (arr.ds[i] > input.max)
		{
			ri = i;
			break;
		}
		i++;
	}
	*small = arr.ds[li + (long)((double)(ri - li) * 0.3333333333)];
	*big = arr.ds[li + (long)((double)(ri - li) * 0.66666666667)];
}
