/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:48:55 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:00:41 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../fr_read.h"

int		init_reading(char c)
{
	t_tokenizer	*tknzr;

	tknzr = &parser()->tknzr;
	destroy_str(&tknzr->reading);
	tknzr->reading = create_str();
	str_push_char(&tknzr->reading, c);
	return (1);
}

char	fr_read_track(void)
{
	char		result;
	t_tokenizer	*tknzr;

	tknzr = &parser()->tknzr;
	result = fr_read();
	tknzr->unresolved_row = parser()->fr.c_row;
	tknzr->unresolved_col = parser()->fr.c_col;
	tknzr->unresolved_char = result;
	return (result);
}

void	reading_push_char(char c)
{
	str_push_char(&parser()->tknzr.reading, c);
}

int		init_reading_by_next(void)
{
	return (init_reading(fr_read_track()));
}
