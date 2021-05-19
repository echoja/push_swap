/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:56:15 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:01:31 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fr_read.h"
#include "push_swap.h"

char
	fr_read(void)
{
	char	c;

	c = program()->input[program()->input_next];
	if (c)
	{
		program()->input_next++;
	}
	return (c);
}
