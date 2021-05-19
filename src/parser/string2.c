/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:37:46 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/03 18:11:13 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

void	write_str(t_str str)
{
	write(1, raw(str), str.len);
}

void	str_push_long(t_str *str, long num)
{
	if (num < 0)
	{
		str_push_char(str, '-');
		num *= -1;
	}
	if (num >= 10)
		str_push_long(str, num / 10);
	str_push_char(str, (num % 10) + '0');
}

void	str_push_double(t_str *str, double num, unsigned int round)
{
	long			n;
	double			small;
	long			minus;
	unsigned int	i;

	minus = 1;
	if (num < 0)
		minus = -1;
	n = (long)num;
	small = (num - n) * minus;
	str_push_long(str, n);
	if (small > 0)
		str_push_char(str, '.');
	i = 0;
	while (small > 0)
	{
		small *= 10;
		n = (long)small;
		str_push_char(str, n + '0');
		small -= n;
		i++;
		if (i >= round)
			break ;
	}
}

void	str_push_chars(t_str *str, const char *s)
{
	t_ul	i;

	i = 0;
	while (s[i])
	{
		str_push_char(str, s[i]);
		i++;
	}
}

void	str_push_char(t_str *str, char c)
{
	t_ul	i;
	char	*new_ptr;

	str->ptr[str->len] = c;
	str->len += 1;
	if (str->len > str->max / 2)
	{
		str->max *= 2;
		new_ptr = (char *)malloc(sizeof(char) * str->max);
		if (!new_ptr)
			exit(ERR_STR_PUSH_CHAR_ALLOC);
		i = 0;
		while (i < str->len)
		{
			new_ptr[i] = str->ptr[i];
			i++;
		}
		free(str->ptr);
		str->ptr = new_ptr;
	}
}
