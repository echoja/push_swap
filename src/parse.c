/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:11:06 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:48:45 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "push_swap.h"

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
			abort_parser("should be a number", ERR_PARSE);
	}
}

void
	parse_b(void)
{
	init_parser_fd(0, "stdin");
	parse_numbers();
	finish_parser();
}
