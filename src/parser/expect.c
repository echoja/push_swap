/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:55:35 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/03 17:55:46 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_str	expect_type(t_token_type type)
{
	t_token	token;

	token = next_token();
	if (token.type != type)
		abort_parser_type(type);
	return (token.str);
}

long	expect_int_range(long min, long max)
{
	t_str	str;
	long	result;

	str = expect_type(TOKEN_INT);
	result = str_to_long(str);
	if (result < min || result > max)
		abort_parser_range((double)min, (double)max);
	return (result);
}

double	expect_number_range(double min, double max)
{
	double	num;

	num = expect_number();
	if (num < min || num > max)
		abort_parser_range(min, max);
	return (num);
}

double	expect_number(void)
{
	t_token	token;
	double	num;

	token = next_token();
	if (token.type != TOKEN_DOUBLE && token.type != TOKEN_INT)
		abort_parser("expected number", ERR_PARSE);
	if (token.type == TOKEN_DOUBLE)
		num = (str_to_double(token.str));
	else
		num = (double)(str_to_long(token.str));
	return (num);
}
