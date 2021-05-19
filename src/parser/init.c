/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:06:15 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/17 21:20:47 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		init_parser(const char *path)
{
	t_parser	*p;
	int			fd;

	p = parser();
	p->tknzr = create_tokenizer();
	p->fr = fr(path);
	file_open(&fd, path);
	p->fr.fd = fd;
	p->custom_err_handler = 0;
	init_tokenizer();
}

void			init_parser_fd(int fd, const char *name)
{
	t_parser	*p;

	p = parser();
	p->tknzr = create_tokenizer();
	p->fr = fr(name);
	p->fr.fd = fd;
	p->custom_err_handler = 0;
	init_tokenizer();
}
