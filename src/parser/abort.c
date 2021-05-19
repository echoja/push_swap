/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 01:52:46 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/27 17:48:42 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"


void	abort_file(const char *msg, int errcode)
{
	t_str	str;

	str = create_str();
	str_push_chars(&str, msg);
	str_push_chars(&str, ": ");
	str_push_chars(&str, parser()->fr.path);
	str_push_chars(&str, "\n");
	write_str(str);
	finish_parser();
	destroy_str(&str);
	if (parser()->custom_err_handler)
		parser()->custom_err_handler(parser()->err_arg);
	else
		exit(errcode);
}

void	abort_parser(const char *msg, int errcode)
{
	t_token	token;
	t_str	str;

	str = create_str();
	token = token_lookahead();
	str_push_chars(&str, msg);
	str_push_chars(&str, ": '");
	str_push_chars(&str, raw(token.str));
	str_push_chars(&str, "' (");
	str_push_chars(&str, parser()->fr.path);
	str_push_char(&str, ':');
	str_push_long(&str, token.file_row);
	str_push_char(&str, ':');
	str_push_long(&str, token.file_col);
	str_push_chars(&str, ")\n");
	write_str(str);
	finish_parser();
	destroy_str(&str);
	if (parser()->custom_err_handler)
		parser()->custom_err_handler(parser()->err_arg);
	else
		exit(errcode);
}

void	abort_parser_range(double min, double max)
{
	t_str	str;

	str = create_str();
	str_push_chars(&str, "number should be >= ");
	str_push_double(&str, min, 1);
	str_push_chars(&str, ", <= ");
	str_push_double(&str, max, 1);
	abort_parser(raw(str), ERR_PARSE);
	destroy_str(&str);
	if (parser()->custom_err_handler)
		parser()->custom_err_handler(parser()->err_arg);
	else
		exit(ERR_PARSE);
}

void	abort_parser_type(t_token_type type)
{
	if (type == TOKEN_COMMA)
		abort_parser("expected comma", ERR_PARSE);
	else if (type == TOKEN_DOUBLE)
		abort_parser("expected double", ERR_PARSE);
	else if (type == TOKEN_INT)
		abort_parser("expected integer", ERR_PARSE);
	else if (type == TOKEN_NAME)
		abort_parser("expected name", ERR_PARSE);
	else if (type == TOKEN_NEWLINE)
		abort_parser("expected newline", ERR_PARSE);
	else
		abort_parser("unexpected token type", ERR_PARSE);
}

void	abort_tokenizer(void)
{
	t_str		str;
	t_tokenizer	tknzr;

	tknzr = parser()->tknzr;
	str = create_str();
	str_push_chars(&str, "Unexpected Token '");
	str_push_char(&str, tknzr.unresolved_char);
	str_push_chars(&str, "' at ");
	str_push_chars(&str, parser()->fr.path);
	str_push_char(&str, ':');
	str_push_long(&str, tknzr.unresolved_row);
	str_push_char(&str, ':');
	str_push_long(&str, tknzr.unresolved_col);
	str_push_char(&str, '\n');
	write_str(str);
	destroy_str(&str);
	if (parser()->custom_err_handler)
		parser()->custom_err_handler(parser()->err_arg);
	else
		exit(ERR_TOKEN_CONSUME);
}
