/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:53:07 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 20:44:18 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <stdlib.h>

void		set_parser_err_handler(void (*func)(void *), void *err_arg)
{
	parser()->custom_err_handler = func;
	parser()->err_arg = err_arg;
}

void		finish_parser(void)
{
	safe_file_close();
	destroy_str(&parser()->tknzr.reading);
	destroy_str(&parser()->tknzr.current_token.str);
}

t_parser	*parser(void)
{
	static t_parser	p;

	return (&p);
}

t_token		next_token(void)
{
	token_consume();
	return (token_lookahead());
}
