/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:27:09 by taehokim          #+#    #+#             */
/*   Updated: 2021/04/27 17:48:42 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include <errno.h>

#include <string.h>

int				file_open(int *fd, const char *path)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		abort_file("file open failed", ERR_FILE_OPEN);
	return (1);
}

int				safe_file_close(void)
{
	int	result;

	if (parser()->fr.fd != -1)
	{
		result = close(parser()->fr.fd);
		if (result == -1)
			abort_parser("file close failed", ERR_FILE_CLOSE);
		parser()->fr.fd = -1;
	}
	return (1);
}

t_filereader	fr(const char *path)
{
	t_filereader	fr;

	fr.path = path;
	fr.eof_reached = 0;
	fr.eof_reached_len = 0;
	fr.pos = BUF_SIZE;
	fr.c_row = 1;
	fr.c_col = 0;
	fr.fd = -1;
	return (fr);
}

void			read_to_buffer(t_filereader *fr)
{
	int				n_read;
	int				i;

	fr->pos = 0;
	n_read = read(fr->fd, fr->buf, BUF_SIZE);
	if (n_read == -1)
		abort_parser("Error occurred while reading", ERR_READ);
	if (n_read < BUF_SIZE)
	{
		fr->eof_reached = 1;
		fr->eof_reached_len = n_read;
		i = n_read - 1;
		while (++i < BUF_SIZE)
			fr->buf[i] = '\0';
	}
}

int				make_frpos_safe(t_filereader *fr)
{
	int				border;

	if (fr->eof_reached)
		border = fr->eof_reached_len;
	else
		border = BUF_SIZE;
	if (fr->eof_reached && fr->pos >= border)
		return (0);
	if (fr->pos >= border)
		read_to_buffer(fr);
	return (1);
}
