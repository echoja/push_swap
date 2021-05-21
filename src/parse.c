/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:11:06 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 00:31:54 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parser/parser.h"
#include "push_swap.h"

void
	write_error_chars(const char *chars)
{
	long	len;

	len = 0;
	while (chars[len])
		len++;
	write(2, chars, len);
}

void
	error_parser(void)
{
	finish_parser();
	free_program_and_exit(1);
}

int
	parse_numbers(void)
{
	t_token	token;
	long	num;

	while (1)
	{
		token = next_token();
		if (token.type == TOKEN_NEWLINE)
			continue ;
		else if (token.type == TOKEN_INT)
		{
			num = str_to_long(token.str);
			push_new(&program()->b, num);
			if (num < INT_MIN || num > INT_MAX)
				return (0);
		}
		else if (token.type == TOKEN_END)
			break ;
		else
			error_parser();
	}
	return (1);
}

int
	parse_b(void)
{
	int	result;

	init_parser_fd(0, "stdin");
	result = parse_numbers();
	finish_parser();
	return (result);
}
