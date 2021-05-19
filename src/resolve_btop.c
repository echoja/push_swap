/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_btop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:49:11 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 03:00:24 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	resolve_btop3(t_stack_item *top)
{
	long	d1;
	long	d2;
	long	d3;

	d1 = top->prev->prev->data;
	d2 = top->prev->data;
	d3 = top->data;
	if (d1 > d2 && d1 > d3)
	{
		if (d2 > d3)
			sb();
		pa();
		rr();
		pa();
		rrr();
		return (pa());
	}
	if (d2 > d1 && d2 > d3)
		sb();
	pa();
	pa();
	pa();
	if ((d1 < d2 && d1 > d3) || (d1 > d2 && d1 < d3))
		sa();
}

void
	resolve_btop_divide(long len, t_calc *c)
{
	long			i;
	t_stack_item	*comp;

	i = -1;
	comp = program()->b.top;
	while (++i < len)
	{
		if (comp->data > c->piv_low)
		{
			pa();
			if (comp->data < c->piv_high)
			{
				ra();
				c->len2++;
			}
			else
				c->len3++;
		}
		else
		{
			rb();
			c->len1++;
		}
		comp = program()->b.top;
	}
}

void
	resolve_btop2(long min, long max, t_calc c)
{
	long	i;

	i = -1;
	while (++i < c.len1)
		rrb();
	resolve_atop(c.len3, c.piv_high, max);
	i = -1;
	while (++i < c.len2)
		rra();
	resolve_atop(c.len2, c.piv_low + 1, c.piv_high - 1);
	resolve_btop(c.len1, min, c.piv_low);
}

void
	resolve_btop(long len, long min, long max)
{
	t_stack_item	*top;
	t_calc			c;

	if (len == 0 || len > program()->b.len)
		return ;
	if (len == 1)
		return (pa());
	top = program()->b.top;
	if (len == 2)
	{
		if (top->data < top->prev->data)
			sb();
		pa();
		return (pa());
	}
	if (len == 3)
		return (resolve_btop3(top));
	init_calc(&c, min, max);
	resolve_btop_divide(len, &c);
	resolve_btop2(min, max, c);
}
