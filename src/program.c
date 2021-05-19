/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:03:20 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 02:37:53 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_program
	*program(void)
{
	static t_program	instance;

	return (&instance);
}

int
	is_duplicated(t_arr arr)
{
	long	i;
	long	len;
	long	*ds;

	i = 0;
	len = arr.len;
	ds = arr.ds;
	while (i < len - 1)
	{
		if (ds[i] == ds[i + 1])
			return (1);
		i++;
	}
	return (0);
}
