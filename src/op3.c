/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:53:34 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 03:01:35 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void
	write_chars(const char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
		i++;
	write(1, chars, i);
}

void
	resolve_lazy(void)
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

void
	rrr(void)
{
	resolve_lazy();
	srrotate(&program()->a);
	srrotate(&program()->b);
	write_chars("rrr\n");
}
