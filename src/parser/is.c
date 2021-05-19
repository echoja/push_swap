/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:37:34 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/03 17:44:59 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_no_zero_digit(char c)
{
	return (c >= '1' && c <= '9');
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_c_name(char c)
{
	return (is_alpha(c) || one_of(c, "_"));
}

int	one_of(char c, const char *list)
{
	int	i;

	i = 0;
	while (list[i] != '\0')
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}
