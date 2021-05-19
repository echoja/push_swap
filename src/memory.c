/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:00:09 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/18 21:59:57 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	m(void *target, size_t size)
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
