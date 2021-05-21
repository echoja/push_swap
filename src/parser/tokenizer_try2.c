/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_try2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:46:51 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/21 22:25:53 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		try_token_int(void)
{
	char	c;

	c = raw(parser()->tknzr.reading)[0];
	if (c == '0')
		return (confirm_trial_init_next(TOKEN_INT));
	if (c == '-')
	{
		c = fr_read_track();
		reading_push_char(c);
	}
	if (is_no_zero_digit(c))
	{
		while (1)
		{
			c = fr_read_track();
			if (!is_digit(c))
				break ;
			reading_push_char(c);
		}
		return (confirm_trial(TOKEN_INT, c));
	}
	else if (c == '0')
		return (confirm_trial_init_next(TOKEN_INT));
	return (0);
}

int		iterate_double(char c)
{
	t_str		temp;
	t_tokenizer	*tknzr;

	tknzr = &parser()->tknzr;
	reading_push_char(c);
	while (1)
	{
		c = fr_read_track();
		if (!is_digit(c))
			break ;
		reading_push_char(c);
	}
	temp = duplicate_str(tknzr->current_token.str);
	concat_str(&temp, tknzr->reading);
	confirm_trial_value(TOKEN_DOUBLE, c, temp);
	destroy_str(&temp);
	return (1);
}

void	skip_blank(void)
{
	char		c;

	c = raw(parser()->tknzr.reading)[0];
	if (c == ' ')
	{
		while (1)
		{
			c = fr_read_track();
			if (c != ' ')
				break ;
		}
	}
	init_reading(c);
}
