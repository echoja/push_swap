/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:51:39 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 03:30:15 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "parser/parser.h"

long get_strlen(const char *str)
{
	long i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int check_num(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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
	main_one_arg(char *argv1)
{
	long i;
	long len;

	program()->input = argv1;
	parse_b();
	i = -1;
	len = program()->b.len;
	while (++i < len)
		smove(&program()->a, &program()->b);
	init_sorted_arr_from_a();
	if (is_duplicated(program()->arr))
		free_program_and_exit(1);
	resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	return (0);
}

int
	main_many_arg(int argc, char *argv[])
{
	long i;
	long num;
	long len;

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
	i = -1;
	len = program()->b.len;
	while (++i < len)
		smove(&program()->a, &program()->b);
	init_sorted_arr_from_a();
	if (is_duplicated(program()->arr))
		free_program_and_exit(1);
	resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	return (0);
}

int
	main(int argc, char *argv[])
{
	if (argc == 2)
		main_one_arg(argv[1]);
	else if (argc >= 3)
		main_many_arg(argc, argv);
	resolve_lazy();
	return (0);
}
