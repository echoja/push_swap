/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:11:06 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 02:45:39 by taehokim         ###   ########.fr       */
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
	write_error_chars("Error\n");
	exit(1);
}

void
	parse_numbers(void)
{
	t_token	token;

	while (1)
	{
		token = next_token();
		if (token.type == TOKEN_NEWLINE)
			continue ;
		else if (token.type == TOKEN_INT)
			push_new(&program()->b, str_to_long(token.str));
		else if (token.type == TOKEN_END)
			break ;
		else
			error_parser();
	}
}

void
	parse_b(void)
{
	init_parser_fd(0, "stdin");
	parse_numbers();
	finish_parser();
}
