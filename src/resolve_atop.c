/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_atop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:16:17 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 03:00:53 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	resolve_atop3(t_stack_item *top)
{
	long			d1;
	long			d2;
	long			d3;

	d1 = top->prev->prev->data;
	d2 = top->prev->data;
	d3 = top->data;
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

void
	resolve_atop_divide(long len, t_calc *c)
{
	t_stack_item	*comp;
	long			i;

	i = -1;
	comp = program()->a.top;
	while (++i < len)
	{
		if (comp->data < c->piv_high)
		{
			pb();
			if (comp->data > c->piv_low)
			{
				rb();
				c->len2++;
			}
			else
				c->len1++;
		}
		else
		{
			ra();
			c->len3++;
		}
		comp = program()->a.top;
	}
}

void
	resolve_atop_move(t_calc c)
{
	long	i;

	i = 0;
	while (i < c.len2 || i < c.len3)
	{
		if (i < c.len2)
			rrb();
		if (i < c.len3)
			rra();
		i++;
	}
}

void
	resolve_atop(long len, long min, long max)
{
	t_stack_item	*top;
	t_calc			c;

	if (len == 0 || len == 1 || len > program()->a.len)
		return ;
	top = program()->a.top;
	if (len == 2)
	{
		if (top->data > top->prev->data)
			sa();
		return ;
	}
	if (len == 3)
		return (resolve_atop3(top));
	init_calc(&c, min, max);
	resolve_atop_divide(len, &c);
	resolve_atop_move(c);
	resolve_atop(c.len3, c.piv_high, max);
	resolve_btop(c.len2, c.piv_low, c.piv_high - 1);
	resolve_btop(c.len1, min, c.piv_low - 1);
}
