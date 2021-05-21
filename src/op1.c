/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:27:19 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 03:21:03 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void
	sa(void)
{
	sswap(&program()->a);
	if (program()->called_sb)
	{
		program()->called_sb = 0;
		if (program()->op_echo)
			write_chars("ss\n");
		return ;
	}
	resolve_lazy();
	program()->called_sa = 1;
}

void
	sb(void)
{
	sswap(&program()->b);
	if (program()->called_sa)
	{
		program()->called_sa = 0;
		if (program()->op_echo)
			write_chars("ss\n");
		return ;
	}
	resolve_lazy();
	program()->called_sb = 1;
}

void
	ss(void)
{
	resolve_lazy();
	sswap(&program()->a);
	sswap(&program()->b);
	if (program()->op_echo)
		write(1, "ss\n", 3);
}

void
	pa(void)
{
	resolve_lazy();
	smove(&program()->a, &program()->b);
	if (program()->op_echo)
		write(1, "pa\n", 3);
}

void
	pb(void)
{
	resolve_lazy();
	smove(&program()->b, &program()->a);
	if (program()->op_echo)
		write(1, "pb\n", 3);
}
