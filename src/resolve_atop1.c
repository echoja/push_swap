/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_atop1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:16:17 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/21 21:56:17 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void
	resolve_atop_divide_loop(t_stack_item *comp, t_calc *c)
{
	pb();
	if (c->start_blen) {
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
		if (comp->data > c->piv_low)
			c->len2++;
		else
		{
			rb();
			c->len1++;
		}
	}
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
			resolve_atop_divide_loop(comp, c);
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
		if (i < c.len2 && c.start_blen)
			rrb();
		if (i < c.len3 && c.len3 != program()->a.len)
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
	init_calc(&c, min, max);
	if (len == 3)
		return (resolve_atop3(top, c));
	resolve_atop_divide(len, &c);
	resolve_atop_move(c);
	resolve_atop(c.len3, c.piv_high, max);
	if (program()->b.len == c.len2 + c.len1 && program()->b.len <= 3)
		resolve_small_b(program()->b.len, program()->b.top);
	else
	{
		resolve_btop(c.len2, c.piv_low, c.piv_high - 1);
		resolve_btop(c.len1, min, c.piv_low - 1);
	}
}
