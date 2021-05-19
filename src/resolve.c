/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:16:17 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:30:36 by taehokim         ###   ########.fr       */
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
	resolve_btop3(t_stack_item *top)
{
	long			d1;
	long			d2;
	long			d3;

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
	init_calc(t_calc *c, long min, long max)
{
	long	sw;
	t_pvipt	input;

	input.min = min;
	input.max = max;
	get_appropriate_pivot(program()->arr, &c->piv_low, &c->piv_high, input); // todo: need check
	// c->piv_low = top->prev->data;
	// c->piv_high = top->data;
	if (c->piv_high < c->piv_low)
	{
		sw = c->piv_high;
		c->piv_high = c->piv_low;
		c->piv_low = sw;
	}
	c->len1 = 0;
	c->len2 = 0;
	c->len3 = 0;
}

void
	resolve_atop(long len, long min, long max)
{
	t_stack_item	*top;
	t_stack_item	*comp;
	t_calc			c;
	long			i;

	// printf("resolve atop started: %ld\n", len);
	// printf("before %ld\n", len);
	// print_stack(program()->a);
	// print_stack(program()->b);
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
	// init_calc(&c, program()->a.top, min, max);
	// printf("pivot: %ld %ld\n", c.piv_low, c.piv_high);
	i = 0;
	comp = program()->a.top;
	while (i < len)
	{
		if (comp->data < c.piv_high)
		{
			pb();
			if (comp->data > c.piv_low)
			{
				rb();
				c.len2++;
			}
			else
				c.len1++;
		}
		else
		{
			ra();
			c.len3++;
		}
		i++;
		comp = program()->a.top;
	}
	i = 0;
	// 3번과 2번을 옮기기
	while (i < c.len2 || i < c.len3)
	{
		if (i < c.len2)
			rrb();
		if (i < c.len3)
			rra();
		i++;
	}
	// 3번 정렬
	resolve_atop(c.len3, c.piv_high, max);
	// 2번 정렬
	resolve_btop(c.len2, c.piv_low, c.piv_high - 1);
	// 1번 정렬
	resolve_btop(c.len1, min, c.piv_low - 1);
}

void
	resolve_btop(long len, long min, long max)
{
	t_stack_item	*top;
	t_stack_item	*comp;
	t_calc			c;
	long			i;

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
	i = 0;
	comp = program()->b.top;
	while (i < len)
	{
		if (comp->data > c.piv_low)
		{
			pa();
			if (comp->data < c.piv_high)
			{
				ra();
				c.len2++;
			}
			else
				c.len3++;
		}
		else
		{
			rb();
			c.len1++;
		}
		comp = program()->b.top;
		i++;
	}
	// 1번 옮김
	i = -1;
	while (++i < c.len1)
		rrb();
	// 3번 정렬
	resolve_atop(c.len3, c.piv_high, max);
	// 2번 옮김
	i = -1;
	while (++i < c.len2)
		rra();
	// 2번 정렬
	resolve_atop(c.len2, c.piv_low + 1, c.piv_high - 1);
	// 1번 정렬
	resolve_btop(c.len1, min, c.piv_low);

}
