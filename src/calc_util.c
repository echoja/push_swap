/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:27:59 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/21 22:25:34 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

long
	get_strlen(const char *str)
{
	long i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void
	get_appropriate_pivot(t_arr arr, long *small, long *big, t_pvipt input)
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
			break ;
		}
		i++;
	}
	*small = arr.ds[li + (long)((double)(ri - li) * 0.3333333333)];
	*big = arr.ds[li + (long)((double)(ri - li) * 0.66666666667)];
}

void
	init_calc(t_calc *c, long min, long max)
{
	long	sw;
	t_pvipt	input;

	input.min = min;
	input.max = max;
	get_appropriate_pivot(program()->arr, &c->piv_low, &c->piv_high, input);
	if (c->piv_high < c->piv_low)
	{
		sw = c->piv_high;
		c->piv_high = c->piv_low;
		c->piv_low = sw;
	}
	c->len1 = 0;
	c->len2 = 0;
	c->len3 = 0;
	c->start_alen = program()->a.len;
	c->start_blen = program()->b.len;
}
