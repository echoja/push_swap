/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:57 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/03 17:56:11 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <math.h>

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

double	str_to_double2(t_str str, t_ul dot_point)
{
	long	minus;
	t_str	intpart;
	long	left;
	long	right;

	intpart = duplicate_str_with_range(str, 0, dot_point);
	left = str_to_long(intpart);
	destroy_str(&intpart);
	intpart = duplicate_str_with_range(str, dot_point + 1, str.len);
	right = str_to_long(intpart);
	minus = 1;
	if (raw(str)[0] == '-')
		minus = -1;
	destroy_str(&intpart);
	return ((double)left
		+ (double)pow(10.0, -(double)(str.len - dot_point - 1))
		* (double)right * (double)minus);
}

double	str_to_double(t_str str)
{
	t_ul	dot_point;
	t_ul	i;

	i = 0;
	dot_point = 0;
	while (i < str.len)
	{
		if (raw(str)[i] == '.')
		{
			dot_point = i;
			break ;
		}
		i++;
	}
	if (dot_point == 0)
		return (0.0);
	return (str_to_double2(str, dot_point));
}
