/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:24:10 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 02:47:22 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser/parser.h"

long
	stol(const char *s)
{
	t_ul	i;
	int		minus;
	long	result;
	long	changing;

	result = 0;
	minus = 1;
	i = 0;
	if (s[0] == '-')
	{
		minus = -1;
		i = 1;
	}
	while (s[i])
	{
		changing = result * 10 + (s[i] - '0');
		if (changing > INT_MAX || changing * minus < INT_MIN)
			free_program_and_exit(1);
		result = changing;
		i++;
	}
	return (result * minus);
}

int
	get_one_arg(char *argv1)
{
	program()->input = argv1;
	if (!parse_b())
		free_program_and_exit(1);
	return (0);
}

int
	get_many_arg(int argc, char *argv[])
{
	long	i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!check_num(argv[i]))
			free_program_and_exit(1);
		num = stol(argv[i]);
		if (num >= INT_MAX)
			free_program_and_exit(1);
		push_new(&program()->b, stol(argv[i]));
		i++;
	}
	return (0);
}

void
	preprocess(int argc, char *argv[])
{
	long	i;
	long	len;

	if (argc == 2)
		get_one_arg(argv[1]);
	else if (argc >= 3)
		get_many_arg(argc, argv);
	i = -1;
	len = program()->b.len;
	while (++i < len)
		smove(&program()->a, &program()->b);
	init_sorted_arr_from_a();
	if (is_duplicated(program()->arr))
		free_program_and_exit(1);
}
