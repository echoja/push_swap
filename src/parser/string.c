/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:22:29 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 04:34:21 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include <unistd.h>

t_str	create_str(void)
{
	t_str	str;

	str.len = 0;
	str.max = INITIAL_STR_LEN;
	str.ptr = (char *)malloc(sizeof(char) * INITIAL_STR_LEN);
	if (!str.ptr)
		exit(ERR_STR_ALLOC);
	return (str);
}

t_str	duplicate_str(t_str str)
{
	t_str	new_str;
	t_ul	i;

	new_str.max = str.max;
	new_str.len = str.len;
	new_str.ptr = (char *)malloc(sizeof(char) * str.max);
	if (!new_str.ptr)
		exit(ERR_STR_ALLOC);
	i = 0;
	while (i < str.len)
	{
		(new_str.ptr)[i] = (str.ptr)[i];
		i++;
	}
	return (new_str);
}

void	concat_str(t_str *target, t_str source)
{
	t_ul		i;
	const char	*raw_str;

	raw_str = raw(source);
	i = 0;
	while (i < source.len)
	{
		str_push_char(target, raw_str[i]);
		i++;
	}
}

t_str	duplicate_str_with_range(t_str str, t_ul start, t_ul end)
{
	t_str		new_str;
	t_ul		i;
	t_ul		border;
	const char	*target_raw;

	target_raw = raw(str);
	border = end;
	if (border > str.len)
		border = str.len;
	i = start;
	new_str = create_str();
	while (i < border)
	{
		str_push_char(&new_str, target_raw[i]);
		i++;
	}
	return (new_str);
}

void	destroy_str(t_str *str)
{
	if (str->ptr)
		free(str->ptr);
	str->ptr = 0;
	str->len = 0;
	str->max = 0;
}
