/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:53:34 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:25:58 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void write_chars(const char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
		i++;
	write(1, chars, i);
}

void	resolve_lazy(void)
{
	if (program()->called_ra)
		write_chars("ra\n");
	if (program()->called_rb)
		write_chars("rb\n");
	if (program()->called_rra)
		write_chars("rra\n");
	if (program()->called_rrb)
		write_chars("rrb\n");
	if (program()->called_sa)
		write_chars("sa\n");
	if (program()->called_sb)
		write_chars("sb\n");
	program()->called_ra = 0;
	program()->called_rb = 0;
	program()->called_rra = 0;
	program()->called_rrb = 0;
	program()->called_sa = 0;
	program()->called_sb = 0;
}

void sa(void)
{
	// write_chars("## real sa\n");
	sswap(&program()->a);
	if (program()->called_sb)
	{
		program()->called_sb = 0;
		return (write_chars("ss\n"));
	}
	resolve_lazy();
	program()->called_sa = 1;
}

void sb(void)
{
	// write_chars("## real sb\n");
	sswap(&program()->b);
	if (program()->called_sa)
	{
		program()->called_sa = 0;
		return (write_chars("ss\n"));
	}
	resolve_lazy();
	program()->called_sb = 1;
}

void ss(void)
{
	resolve_lazy();
	// write_chars("## real ss\n");
	sswap(&program()->a);
	sswap(&program()->b);
	write(1, "ss\n", 3);
}

void pa(void)
{
	resolve_lazy();
	// write_chars("## real pa\n");
	smove(&program()->a, &program()->b);
	write(1, "pa\n", 3);
}

void pb(void)
{
	resolve_lazy();
	// write_chars("## real pb\n");
	smove(&program()->b, &program()->a);
	write(1, "pb\n", 3);
}

void ra(void)
{
	// write_chars("## real ra\n");
	srotate(&program()->a);
	if (program()->called_rb)
	{
		program()->called_rb = 0;
		return (write_chars("rr\n"));
	}
	resolve_lazy();
	program()->called_ra = 1;
}

void rb(void)
{
	// write_chars("## real rb\n");
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
	// write_chars("## real rr\n");
	srotate(&program()->a);
	srotate(&program()->b);
	write_chars("rr\n");
}

void
	rra(void)
{
	// write_chars("## real rra\n");
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
	// write_chars("## real rrb\n");
	srrotate(&program()->b);
	if (program()->called_rra)
	{
		program()->called_rra = 0;
		return (write_chars("rrr\n"));
	}
	resolve_lazy();
	program()->called_rrb = 1;
}

void
	rrr(void)
{
	resolve_lazy();
	// write_chars("## real rrr\n");
	srrotate(&program()->a);
	srrotate(&program()->b);
	write_chars("rrr\n");
}

// void
// 	lazy_rra(void)
// {
// 	if (program()->called_rrb)
// 	{
// 		program()->called_rra = 0;
// 		program()->called_rrb = 0;
// 		return (rrr());
// 	}
// 	resolve_lazy();
// 	program()->called_rra = 1;
// }

// void lazy_rrb(void)
// {
// 	if (program()->called_rra)
// 	{
// 		program()->called_rra = 0;
// 		program()->called_rrb = 0;
// 		return (rrr());
// 	}
// 	resolve_lazy();
// 	program()->called_rrb = 1;
// }

// void lazy_ra(void)
// {
// 	if (program()->called_rb)
// 	{
// 		program()->called_ra = 0;
// 		program()->called_rb = 0;
// 		return (rr());
// 	}
// 	resolve_lazy();
// 	program()->called_ra = 1;
// }

// void lazy_rb(void)
// {
// 	if (program()->called_ra)
// 	{
// 		program()->called_ra = 0;
// 		program()->called_rb = 0;
// 		return (rr());
// 	}
// 	resolve_lazy();
// 	program()->called_rb = 1;
// }

// void lazy_sa(void)
// {
// 	if (program()->called_sb)
// 	{
// 		program()->called_sa = 0;
// 		program()->called_sb = 0;
// 		return (ss());
// 	}
// 	resolve_lazy();
// 	program()->called_sa = 1;
// }

// void lazy_sb(void)
// {
// 	if (program()->called_sa)
// 	{
// 		program()->called_sa = 0;
// 		program()->called_sb = 0;
// 		return (ss());
// 	}
// 	resolve_lazy();
// 	program()->called_sb = 1;
// }

