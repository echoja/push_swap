/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:00:09 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 02:18:12 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int
	m(void *target, size_t size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == 0)
		return (0);
	return (1);
}

void
	safe_free(void *target)
{
	void	**pt;

	pt = (void **)target;
	if (*pt)
	{
		free(*pt);
		*pt = 0;
	}
}

void
	free_program_and_exit(int code)
{
	long	dumb;

	while (program()->a.top)
		pop_free(&program()->a, &dumb);
	while (program()->b.top)
		pop_free(&program()->b, &dumb);
	safe_free(&program()->arr.ds);
	if (code != 0)
		write_error_chars("Error\n");
	exit(code);
}
