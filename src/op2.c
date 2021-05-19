/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:31:41 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 02:33:02 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ra(void)
{
	srotate(&program()->a);
	if (program()->called_rb)
	{
		program()->called_rb = 0;
		return (write_chars("rr\n"));
	}
	resolve_lazy();
	program()->called_ra = 1;
}

void
	rb(void)
{
	srotate(&program()->b);
	if (program()->called_ra)
	{
		program()->called_ra = 0;
		return (write_chars("rr\n"));
	}
	resolve_lazy();
	program()->called_rb = 1;
}

void
	rr(void)
{
	resolve_lazy();
	srotate(&program()->a);
	srotate(&program()->b);
	write_chars("rr\n");
}

void
	rra(void)
{
	srrotate(&program()->a);
	if (program()->called_rrb)
	{
		program()->called_rrb = 0;
		return (write_chars("rrr\n"));
	}
	resolve_lazy();
	program()->called_rra = 1;
}

void
	rrb(void)
{
	srrotate(&program()->b);
	if (program()->called_rra)
	{
		program()->called_rra = 0;
		return (write_chars("rrr\n"));
	}
	resolve_lazy();
	program()->called_rrb = 1;
}
