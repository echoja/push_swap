/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_confirm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:24:01 by taehokim          #+#    #+#             */
/*   Updated: 2021/03/27 19:53:31 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	confirm_trial_value(t_token_type type, char next, t_str value)
{
	t_tokenizer	*tknzr;

	tknzr = &parser()->tknzr;
	tknzr->current_token.type = type;
	assign_str(&tknzr->current_token.str, value);
	return (init_reading(next));
}

int	confirm_trial(t_token_type type, char next)
{
	return (confirm_trial_value(type, next, parser()->tknzr.reading));
}

int	confirm_trial_init_next(t_token_type type)
{
	return (confirm_trial(type, fr_read_track()));
}
