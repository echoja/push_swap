/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 01:42:50 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 03:42:35 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "parser/parser.h"

void
	operation_len2(const char *b)
{
	if (b[0] == 'p')
	{
		if (b[1] == 'a')
			pa();
		else if (b[1] == 'b')
			pb();
	}
	else if (b[0] == 's')
	{
		if (b[1] == 'a')
			sa();
		else if (b[1] == 'b')
			sb();
		else if (b[1] == 's')
			ss();
	}
	else if (b[0] == 'r')
	{
		if (b[1] == 'a')
			ra();
		else if (b[1] == 'b')
			rb();
		else if (b[1] == 'r')
			rr();
	}
}

void
	operation(int len, const char *b)
{
	if (len == 2)
		operation_len2(b);
	else if (len == 3)
	{
		if (b[2] == 'a')
			rra();
		else if (b[2] == 'b')
			rrb();
		else if (b[2] == 'r')
			rrr();
	}
}

t_str
	get_next_line(int *result)
{
	t_str	str;
	char	c;
	int		r;

	str = create_str();
	while (1)
	{
		r = read(0, &c, 1);
		if (r == -1)
		{
			destroy_str(&str);
			free_program_and_exit(1);
		}
		if (c == '\n' || r == 0)
			break ;
		str_push_char(&str, c);
	}
	*result = r;
	return (str);
}

int
	main(int argc, char *argv[])
{
	int		result;
	t_str	line;

	if (argc == 1)
		return (0);
	preprocess(argc, argv);
	while (1)
	{
		line = get_next_line(&result);
		if (result == 0)
			break ;
		if (!check_line(line.len, raw(line)))
		{
			destroy_str(&line);
			free_program_and_exit(1);
		}
		operation(line.len, raw(line));
		destroy_str(&line);
	}
	destroy_str(&line);
	if (check_sorted())
		write_chars("OK\n");
	else
		write_chars("KO\n");
	return (0);
}
