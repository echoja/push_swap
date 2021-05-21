/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:57 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 04:26:37 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

long	str_to_long(t_str str)
{
	const char	*s;
	t_ul		i;
	int			minus;
	long		result;

	result = 0;
	minus = 1;
	s = raw(str);
	i = 0;
	if (s[0] == '-')
	{
		minus = -1;
		i = 1;
	}
	while (i < str.len)
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * minus);
}

double	str_to_double(t_str str)
{
	(void)str;
	return (0.0);
}
