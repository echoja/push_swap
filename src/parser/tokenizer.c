/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:45:16 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/27 17:48:42 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "parser.h"

void
	init_tokenizer(void)
{
	char	c;

	c = fr_read_track();
	str_push_char(&parser()->tknzr.reading, c);
}

t_tokenizer
	create_tokenizer(void)
{
	t_tokenizer	tknzr;

	tknzr.current_token = create_token();
	tknzr.reading = create_str();
	return (tknzr);
}

t_token
	create_token(void)
{
	t_token	tk;

	tk.str = create_str();
	tk.type = TOKEN_NOT_SPECIFIED;
	tk.file_col = 0;
	tk.file_row = 0;
	return (tk);
}

void
	token_consume(void)
{
	t_tokenizer	*tknzr;

	tknzr = &parser()->tknzr;
	if (tknzr->current_token.type == TOKEN_END)
		return ;
	skip_blank();
	tknzr->current_token.file_col = parser()->fr.c_col;
	tknzr->current_token.file_row = parser()->fr.c_row;
	if (try_token_number())
		return ;
	if (try_token_name())
		return ;
	if (try_token_end())
		return ;
	if (try_token_newline())
		return ;
	if (try_token_comma())
		return ;
	abort_tokenizer();
}

t_token
	token_lookahead(void)
{
	t_tokenizer	*tknzr;

	tknzr = &parser()->tknzr;
	if (tknzr->current_token.type == TOKEN_NOT_SPECIFIED)
		token_consume();
	return (tknzr->current_token);
}
