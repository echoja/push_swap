/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_try.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:35:54 by taehokim          #+#    #+#             */
/*   Updated: 2021/03/27 13:26:18 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	try_token_end(void)
{
	char	c;

	c = raw(parser()->tknzr.reading)[0];
	if (c == '\0')
		return (confirm_trial_init_next(TOKEN_END));
	return (0);
}

int	try_token_newline(void)
{
	char	c;

	c = raw(parser()->tknzr.reading)[0];
	if (c == '\n')
		return (confirm_trial_init_next(TOKEN_NEWLINE));
	return (0);
}

int	try_token_comma(void)
{
	char	c;

	c = raw(parser()->tknzr.reading)[0];
	if (c == ',')
		return (confirm_trial_init_next(TOKEN_COMMA));
	return (0);
}

int	try_token_number(void)
{
	char	c;

	if (!try_token_int())
		return (0);
	c = raw(parser()->tknzr.reading)[0];
	if (c != '.')
		return (init_reading(c));
	c = fr_read_track();
	if (is_digit(c))
		return (iterate_double(c));
	else
		return (0);
}

int	try_token_name(void)
{
	char	c;

	c = raw(parser()->tknzr.reading)[0];
	if (is_c_name(c))
	{
		while (1)
		{
			c = fr_read_track();
			if (!is_c_name(c))
				break ;
			reading_push_char(c);
		}
		return (confirm_trial(TOKEN_NAME, c));
	}
	return (0);
}
