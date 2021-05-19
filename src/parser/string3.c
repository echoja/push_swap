/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:39:09 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/13 13:20:45 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

const char	*raw(t_str str)
{
	str.ptr[str.len] = '\0';
	return (str.ptr);
}

void		assign_str(t_str *str, t_str other)
{
	t_str	temp;

	temp = duplicate_str(other);
	destroy_str(str);
	*str = temp;
}

void		assign_chs(t_str *str, const char *raw)
{
	destroy_str(str);
	*str = create_str_from_raw(raw);
}

int			is_same_str(t_str left, const char *right)
{
	const char	*raw_left;
	t_ul		i;

	i = 0;
	raw_left = raw(left);
	while (i < left.len && right[i] != '\0')
	{
		if (raw_left[i] != right[i])
			return (0);
		i++;
	}
	if (raw_left[i] != right[i])
		return (0);
	return (1);
}

t_str		create_str_from_raw(const char *raw)
{
	t_str	str;
	int		i;

	str = create_str();
	i = 0;
	while (raw[i] != '\0')
	{
		str_push_char(&str, raw[i]);
		i++;
	}
	return (str);
}
