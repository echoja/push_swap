/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_atop2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:55:47 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/21 21:56:15 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	resolve_small_b3(long d1, long d2, long d3)
{
	if (d1 > d2 && d1 > d3)
	{
		if (d2 > d1)
			sb();
		rrb();
	}
	else if (d2 > d1 && d2 > d3)
	{
		if (d1 > d3)
			rb();
		else
			sa();
	}
	pa();
	pa();
	pa();
	if (d3 > d1 && d3 > d2 && d1 > d2)
		sa();
}

void
	resolve_small_b(long len, t_stack_item *top)
{
	long	d1;
	long	d2;
	long	d3;

	d1 = top->prev->prev->data;
	d2 = top->prev->data;
	d3 = top->data;
	if (len == 1)
		return (pa());
	if (len == 2)
	{
		top = program()->b.top;
		if (top->data < top->prev->data)
			sb();
		pa();
		return (pa());
	}
	if (len == 3)
		resolve_small_b3(d1, d2, d3);
}

void
	resolve_atop3_exact(long d1, long d2, long d3)
{
	if (d1 < d2 && d1 < d3)
	{
		if (d2 < d3)
		{
			ra();
			sa();
		}
		else
			rra();
	}
	else if (d1 > d2 && d1 > d3)
	{
		if (d3 > d2)
			sa();
	}
	else
		if (d3 > d2)
			ra();
		else
		{
			rra();
			sa();
		}
}

void
	resolve_atop3(t_stack_item *top, t_calc c)
{
	long	d1;
	long	d2;
	long	d3;

	d1 = top->prev->prev->data;
	d2 = top->prev->data;
	d3 = top->data;
	if (c.start_alen == 3)
		return (resolve_atop3_exact(d1, d2, d3));
	if (d1 > d2 && d1 > d3)
	{
		if (d2 < d3)
			sa();
		return ;
	}
	if (d2 < d3 && d1 < d3)
		sa();
	pb();
	sa();
	pa();
	if (d1 < d2 && d1 < d3)
		sa();
}
